// Func.cpp
#include "Func.h"

template <typename T>
void saveListToFile(const list<T>& items, const string& filename) {
    ofstream out(filename);
    if (!out) throw runtime_error("Cannot open file: " + filename);
    out << items.size() << endl;
    for (const auto& item : items)
        out << item << endl;
    out.close();
}

template <typename T>
void loadListFromFile(list<T>& items, const string& filename) {
    ifstream in(filename);
    if (!in) throw runtime_error("Cannot open file: " + filename);

    size_t count;
    in >> count;
    items.clear();
    for (size_t i = 0; i < count; ++i) {
        T item;
        if (!(in >> item)) {
            cerr << "Failed to read item " << i + 1 << " from file.\n";
            continue;
        }
        items.push_back(item);
    }
    in.close();
}

// Explicit template instantiation for used types
template void saveListToFile<Books>(const list<Books>&, const string&);
template void saveListToFile<Order>(const list<Order>&, const string&);
template void saveListToFile<Library>(const list<Library>&, const string&);
template void saveListToFile<User>(const list<User>&, const string&);

template void loadListFromFile<Books>(list<Books>&, const string&);
template void loadListFromFile<Order>(list<Order>&, const string&);
template void loadListFromFile<Library>(list<Library>&, const string&);
template void loadListFromFile<User>(list<User>&, const string&);

void mainMenu() {
    cout << "\nMain Menu:\n";
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}

void userMenu(const User& user) {
    int choice;
    do {
        cout << "\nUser Menu:\n";
        cout << "1. Order Book\n";
        cout << "2. View My Orders\n";
        cout << "0. Logout\n";
        cout << "Choice: ";
        cin >> choice;
    } while (choice != 0);
}

void adminMenu() {
    int choice;
    do {
        cout << "\nAdmin Menu:\n";
        cout << "1. Change User Role\n";
        cout << "2. Add Library\n";
        cout << "3. Edit Library\n";
        cout << "4. Delete Library\n";
        cout << "0. Logout\n";
        cout << "Choice: ";
        cin >> choice;
    } while (choice != 0);
}

void librarianMenu() {
    int choice;
    do {
        cout << "\nLibrarian Menu:\n";
        cout << "1. Manage Books\n";
        cout << "2. Manage Orders\n";
        cout << "0. Logout\n";
        cout << "Choice: ";
        cin >> choice;
    } while (choice != 0);
}