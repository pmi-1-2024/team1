#include "Func.h"

int main() {
    list<Books> books;
    list<Order> orders;
    list<Library> libraries;
	list<User> users;

    try {
        loadListFromFile<Books>(books, "books.txt");
        loadListFromFile<Order>(orders, "orders.txt");
        loadListFromFile<Library>(libraries, "libraries.txt");
		loadListFromFile<User>(users, "users.txt");

        // Наприклад, виведення:
        for (const auto& b : books) b.print(cout);
        for (const auto& o : orders) o.print(cout);
        for (const auto& l : libraries) l.print(cout);
		for (const auto& u : users) u.print(cout);

        // Додавання нового об'єкта
        // books.push_back(Books(...));

        saveListToFile(books, "books.txt");
        saveListToFile(orders, "orders.txt");
        saveListToFile(libraries, "libraries.txt");
		saveListToFile(users, "users.txt");

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
