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
template void saveListToFile<Order>(const list<Order>&, const string&);
template void saveListToFile<Library>(const list<Library>&, const string&);
template void saveListToFile<User>(const list<User>&, const string&);

template void loadListFromFile<Order>(list<Order>&, const string&);
template void loadListFromFile<Library>(list<Library>&, const string&);
template void loadListFromFile<User>(list<User>&, const string&);


void saveBooksToFile(const list<Books*>& items, const string& filename) {
    ofstream out(filename);
    if (!out) throw runtime_error("Cannot open file: " + filename);

    out << items.size() << endl;

    for (const auto& item : items) {
        if (dynamic_cast<const Ebook*>(item)) {
            out << "EBOOK" << endl;
        }
        else if (dynamic_cast<const PaperBooks*>(item)) {
            out << "PAPERBOOK" << endl;
        }
        else {
            out << "BOOK" << endl;
        }
        out << *item << endl;  // виклик operator<<
    }

    out.close();
}

void loadBooksFromFile(list<Books*>& items, const string& filename) {
    ifstream in(filename);
    if (!in) throw runtime_error("Cannot open file: " + filename);

    size_t count;
    in >> count;
    in.ignore();

    items.clear();
    for (size_t i = 0; i < count; ++i) {
        string type;
        do {
            if (!getline(in, type)) {
                cerr << "Unexpected end of file when reading book type at index " << i + 1 << endl;
                return;
            }
            if (!type.empty() && type.back() == '\r') {
                type.pop_back();
            }
        } while (type.empty());

        Books* item = nullptr;
        if (type == "EBOOK") {
            item = new Ebook();
        }
        else if (type == "PAPERBOOK") {
            item = new PaperBooks();
        }
        else {
            cerr << "Unknown book type at line " << i + 2 << ": " << type << endl;
            continue;
        }

        in >> *item;
        in.ignore();
        items.push_back(item);
    }

    in.close();
}
