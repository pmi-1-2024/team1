#include "Books.h"

// Конструктор за замовчуванням
Books::Books() : ID_book(0), book_name(""), year(0), page_count(0) {}

// Спрощений конструктор
Books::Books(int id, const string& name, int y, int pages)
    : ID_book(id), book_name(name), year(y), page_count(pages) {}

// Гетери
int Books::getID_book() const {
    return ID_book;
}

string Books::getBook_name() const {
    return book_name;
}

int Books::getYear() const {
    return year;
}

int Books::getPages() const {
    return page_count;
}

// Сетери
void Books::setID_book(int id) {
    ID_book = id;
}

void Books::setBook_name(const string& name) {
    book_name = name;
}

void Books::setYear(int y) {
    year = y;
}

void Books::setPages(int p) {
    page_count = p;
}
