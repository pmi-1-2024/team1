#include "Books.h"
Books::Books() : ID_book(0), book_name(" "), year(0), page_count(0) {}
Books::Books(int IDb, string bn, int ye, list<Author> aut, Publisher pub, int pc, list<Genre> gen)
	: ID_book(IDb), book_name(bn), year(ye), authors(aut), publisher(pub), page_count(pc), genres(gen) {}

int Books::getID_book() const { return ID_book; }
string Books::getBook_name() const { return book_name; }
int Books::getYear() const { return year; }
int Books::getPages() const { return page_count; }

void Books::setID_book(int IDb) { ID_book = IDb; }
void Books::setBook_name(string bn) { book_name = bn; }
void Books::setYear(int ye) { year = ye; }
void Books::setPages(int pc) { page_count = pc; }