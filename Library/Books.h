#ifndef BOOKS_H
#define BOOKS_H
#include "BooksStructs.h"
#include "Library.h"
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
	int library_id;
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
	int getLibraryID() const;
	void setLibraryID(int id);

	virtual void print(ostream& os, const Library& lib) const;
	virtual void read(istream& is);
	friend ostream& operator<<(ostream& os, const Books& b);
	friend istream& operator>>(istream& is, Books& b);

};

#endif
