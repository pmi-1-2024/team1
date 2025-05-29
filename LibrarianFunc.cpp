#include "LibrarianFunc.h"

void librarianMenu() {
     cout << "\nLibrarian Menu:\n";
     cout << "1. Manage Books\n";
     cout << "2. Manage Orders\n";
     cout << "0. Logout\n";
     cout << "Choice: ";
}

void librarianMenuHandler() {
    list<Order> orders;
    loadListFromFile(orders, "orders.txt");
    list<Books*> books;
    loadBooksFromFile(books, "books.txt");
    int choice;
    do {
        librarianMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int bookChoice;
            cout << "1. Add Book\n2. Edit Book\n3. Delete Book\nChoice: ";
            cin >> bookChoice;

            if (bookChoice == 1) {
                int type;
                cout << "Select book type:\n1. Paper Book\n2. E-Book\nChoice: ";
                cin >> type;

                Books* b = nullptr;
                if (type == 1) b = new PaperBooks();
                else if (type == 2) b = new Ebook();
                else {
                    cout << "Invalid book type.\n";
                    break;
                }

                try {
                    b->read(cin);
                    bool exists = false;
                    for (const auto& book : books) {
                        if (book->getID_book() == b->getID_book()) {
                            exists = true;
                            break;
                        }
                    }

                    if (exists) {
                        cout << "A book with this ID already exists.\n";
                        delete b;
                    }
                    else {
                        books.push_back(b);
                        saveBooksToFile(books, "books.txt");
                        cout << "Book added.\n";
                    }
                }
                catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                    delete b;
                }
            }
            else if (bookChoice == 2) {
                int id;
                cout << "Enter book ID to edit: ";
                cin >> id;

                bool found = false;
                for (auto& b : books) {
                    if (b->getID_book() == id) {
                        b->read(cin);
                        found = true;
                        cout << "Book updated.\n";
                        break;
                    }
                }

                if (!found) {
                    cout << "Book with ID " << id << " not found.\n";
                }
                else {
                    saveBooksToFile(books, "books.txt");
                }
            }
            else if (bookChoice == 3) {
                int id;
                cout << "Enter book ID to delete: ";
                cin >> id;

                bool found = false;
                for (auto it = books.begin(); it != books.end(); ++it) {
                    if ((*it)->getID_book() == id) {
                        delete* it;
                        books.erase(it);
                        found = true;
                        break;
                    }
                }

                if (found) {
                    saveBooksToFile(books, "books.txt");
                    cout << "Book deleted.\n";
                }
                else {
                    cout << "Book with ID " << id << " not found.\n";
                }
            }
            break;
        }

        case 2: {
            int orderChoice;
            cout << "1. View Orders\n2. Delete Order\nChoice: ";
            cin >> orderChoice;

            if (orderChoice == 1) {
                if (orders.empty()) {
                    cout << "No orders available.\n";
                }
                else {
                    for (const auto& o : orders) {
                        o.print(cout);
                        cout << "------------------\n";
                    }
                }
            }
            else if (orderChoice == 2) {
                int oid;
                cout << "Enter Order ID to delete: ";
                cin >> oid;

                size_t before = orders.size();
                orders.remove_if([oid](const Order& o) {
                    return o.getID_order() == oid;
                    });

                if (orders.size() < before) {
                    saveListToFile(orders, "orders.txt");
                    cout << "Order deleted.\n";
                }
                else {
                    cout << "Order with ID " << oid << " not found.\n";
                }
            }
            break;
        }

        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }

    } while (choice != 0);

    for (Books* b : books) {
        delete b;
    }
    books.clear();
}