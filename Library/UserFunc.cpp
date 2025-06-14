#include "UserFunc.h"

void userMenu(const User& user) {
    cout << "\nUser Menu:\n";
    cout << "1. Order Book\n";
    cout << "2. View My Orders\n";
    cout << "0. Logout\n";
    cout << "Choice: ";
}


void userMenuHandler(const User& user) {
    list<Order> orders;
    loadListFromFile(orders, "orders.txt");
    list<Books*> books;
    loadBooksFromFile(books, "books.txt");
    list<Library> libraries;
    loadListFromFile(libraries, "libraries.txt");

    int choice;
    do {
        userMenu(user);
        cin >> choice;
        if (choice == 1) {
            cout << "Available Books:\n";
            for (const auto& b : books) {
                auto it = find_if(libraries.begin(), libraries.end(),
                    [&](const Library& lib) { return lib.getId_library() == b->getLibraryID(); });

                if (it != libraries.end()) {
                    b->print(cout, *it);
                }
                else {
                    cout << "Library not found for this book.\n";
                }
                cout << "------------------\n";
            }

            Order newOrder;
            try {
                newOrder.read(cin, user.getID());
                orders.push_back(newOrder);
                saveListToFile(orders, "orders.txt");
                cout << "Orders created successful.\n";
            }
            catch (const exception& e) {
                cerr << "Ordering failed: " << e.what() << endl;
            }
        }
        else if (choice == 2) {
            for (const auto& o : orders) {
                if (o.getID_user() == user.getID()) {
                    o.print(cout);
                    cout << "----------------------\n";
                }
            }
        }
    } while (choice != 0);
    for (Books* b : books) {
        delete b;
    }
    books.clear();

}