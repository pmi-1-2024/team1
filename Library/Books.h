#ifndef BOOKS_H
#define BOOKS_H
#include "BooksStructs.h"
#include <list>

class Books
{
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
	virtual ~Books();

	int getID_book() const;
	string getBook_name() const;
	int getYear() const;
	int getPages() const;
	list<Author> getAuthors() const;
	Publisher getPublisher() const;
	list<Genre> getGenres() const;

	virtual void print(ostream& os) const;
	virtual void read(istream& is);
	friend ostream& operator<<(ostream& os, const Books& b);
	friend istream& operator>>(istream& is, Books& b);

};

#endif
