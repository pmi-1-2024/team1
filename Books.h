#ifndef BOOKS_H
#define BOOKS_H

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Books {
private:
    int ID_book;
    string book_name;
    int year;
    int page_count;

    list<string> authors;
    string publisher;
    list<string> genres;

public:
    Books(); // Конструктор за замовчуванням

    // Спрощений конструктор (для JSON і додавання вручну)
    Books(int id, const string& name, int y, int pages);

    // Гетери
    int getID_book() const;
    string getBook_name() const;
    int getYear() const;
    int getPages() const;

    // Сетери
    void setID_book(int id);
    void setBook_name(const string& name);
    void setYear(int y);
    void setPages(int p);
};

#endif
