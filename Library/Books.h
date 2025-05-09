#ifndef BOOKS_H
#define BOOKS_H
#include <iostream>
#include <list>
using namespace std;

struct Author {
	//(ID, name, surname)
	int ID_autor;
	string author_name;
	string surname;
};
struct Publisher {
	//(ID, name, address)
	int ID_publish;
	string publish_name;
	string address;
};
struct Genre {
	//(ID, name)
	int ID_genre;
	string genre_name;
};

class Books
{
	//(åÊíèãè, ïðîñòî êíèãè) - (ID, íàçâó, ð³ê, IDàâòîð(ìîæå áóòè áàãàòî), IDâèäàâíèöòâî, ê³ëüê³ñòü ñòîð³íîê, æàíð)
private:
	int ID_book;
	string book_name;
	int year;
	list<Author> authors;
	Publisher publisher;
	int page_count;
	list<Genre> genres;
public:
	Books();
	Books(int IDb, string bn, int ye, list<Author> aut, Publisher pub, int pc, list<Genre> gen);

	int getID_book() const;
	string getBook_name() const;
	int getYear() const;
	int getPages() const;

	void setID_book(int IDb);
	void setBook_name(string bn);
	void setYear(int ye);
	void setPages(int pc);

};

class Ebook : public Books {
	//(ôîðìàò)
protected:
	int ID_format;
};


#endif
