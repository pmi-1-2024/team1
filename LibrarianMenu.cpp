#include "LibrarianMenu.h"
#include "JsonUtils.h"
#include "Books.h"
#include <iostream>
#include <vector>

using namespace std;

// 📚 Додавання книги
void addBook() {
    int id = 1000 + rand() % 9000;
    string name;
    int year, pages;

    cout << "\n=== Add Book ===\n";
    cout << "Title: ";
    cin >> name;
    cout << "Year: ";
    cin >> year;
    cout << "Page count: ";
    cin >> pages;

    vector<Books> books = loadBooksFromJSON();
    books.emplace_back(id, name, year, pages); // спрощений конструктор
    saveBooksToJSON(books);

    cout << "Book added successfully!\n";
}

// 📚 Перегляд усіх книг
void viewBooks() {
    vector<Books> books = loadBooksFromJSON();
    cout << "\n=== Book List ===\n";
    for (const auto& b : books) {
        cout << "ID: " << b.getID_book()
            << ", Title: " << b.getBook_name()
            << ", Year: " << b.getYear()
            << ", Pages: " << b.getPages() << endl;
    }
}

// ⚙ Меню бібліотекаря
void roleMenuLibrarian() {
    int choice;
    do {
        cout << "\n=== LIBRARIAN MENU ===\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "0. Logout\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addBook(); break;
        case 2: viewBooks(); break;
        case 0: break;
        default: cout << "Invalid option.\n";
        }
    } while (choice != 0);
}
