#include "JsonUtils.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// === Збереження користувачів у файл JSON-подібного формату ===
void saveUsersToJSON(const vector<User>& users) {
    ofstream fout("users.json");
    fout << "\n";
    for (size_t i = 0; i < users.size(); ++i) {
        fout << users[i].getID() << "\n";
        fout << users[i].getName() << "\n";
        fout << users[i].getSurname() << "\n";
        fout << users[i].getEmail() << "\n";
        fout << users[i].getPassword() << "\n";
        fout << users[i].getRole() << "\n";
        if (i < users.size() - 1) fout << "#\n";
    }
    fout.close();
}

// === Завантаження користувачів із JSON-подібного формату ===
vector<User> loadUsersFromJSON() {
    vector<User> users;
    ifstream fin("users.json");
    if (!fin) return users;

    string name, surname, email, password, line;
    int id, role;

    while (getline(fin, line)) {
        if (line == "#") continue;  // розділювач записів
        id = stoi(line);            // читаємо ID

        getline(fin, name);
        getline(fin, surname);
        getline(fin, email);
        getline(fin, password);
        fin.ignore();               // пропускаємо залишок рядка після role
        getline(fin, line);        // читаємо роль
        role = stoi(line);

        User user(name, surname, id, email, password);
        user.setRole(role);        // встановлюємо роль
        users.push_back(user);
    }

    return users;
}

// === BOOKS ===
void saveBooksToJSON(const vector<Books>& books) {
    ofstream fout("books.json");
    fout << "\n";
    for (size_t i = 0; i < books.size(); ++i) {
        fout << books[i].getID_book() << "\n";
        fout << books[i].getBook_name() << "\n";
        fout << books[i].getYear() << "\n";
        fout << books[i].getPages() << "\n";
        if (i < books.size() - 1) fout << "#\n";
    }
    fout.close();
}

vector<Books> loadBooksFromJSON() {
    vector<Books> books;
    ifstream fin("books.json");
    if (!fin) return books;

    string name, line;
    int id, year, pages;

    while (getline(fin, line)) {
        if (line == "#") continue;
        id = stoi(line);
        getline(fin, name);
        getline(fin, line); year = stoi(line);
        getline(fin, line); pages = stoi(line);

        books.emplace_back(id, name, year, pages);
    }

    return books;
}

// === LIBRARIES ===
void saveLibrariesToJSON(const vector<Library>& libraries) {
    ofstream fout("libraries.json");
    fout << "\n";
    for (size_t i = 0; i < libraries.size(); ++i) {
        fout << libraries[i].getID_library() << "\n";
        fout << libraries[i].getLibrary_name() << "\n";
        fout << libraries[i].getLibrary_address() << "\n";
        fout << libraries[i].getLoan_duration() << "\n";
        if (i < libraries.size() - 1) fout << "#\n";
    }
    fout.close();
}

vector<Library> loadLibrariesFromJSON() {
    vector<Library> libraries;
    ifstream fin("libraries.json");
    if (!fin) return libraries;

    string name, address, line;
    int id, duration;

    while (getline(fin, line)) {
        if (line == "#") continue;
        id = stoi(line);
        getline(fin, name);
        getline(fin, address);
        getline(fin, line); duration = stoi(line);

        libraries.emplace_back(id, name, address, duration);
    }

    return libraries;
}

// === ORDERS ===
void saveOrdersToJSON(const vector<Order>& orders) {
    ofstream fout("orders.json");
    fout << "\n";
    for (size_t i = 0; i < orders.size(); ++i) {
        fout << orders[i].getID_order() << "\n";
        fout << orders[i].getID_book() << "\n";
        fout << orders[i].getID_user() << "\n";
        fout << orders[i].getStart_day() << "\n";
        if (i < orders.size() - 1) fout << "#\n";
    }
    fout.close();
}

vector<Order> loadOrdersFromJSON() {
    vector<Order> orders;
    ifstream fin("orders.json");
    if (!fin) return orders;

    int id, bookId, userId, startDay;
    string line;

    while (getline(fin, line)) {
        if (line == "#") continue;
        id = stoi(line);
        getline(fin, line); bookId = stoi(line);
        getline(fin, line); userId = stoi(line);
        getline(fin, line); startDay = stoi(line);

        orders.emplace_back(id, bookId, userId, startDay);
    }

    return orders;
}
