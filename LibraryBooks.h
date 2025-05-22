#ifndef LIBRARYBOOKS_H
#define LIBRARYBOOKS_H
#include "Books.h"

class LibraryBooks
{
	//(ID_l, ID_b, кількість)
private:
	int ID_l;
	list<int> ID_b;
	int count;
public:
	LibraryBooks();
	LibraryBooks(int il, list<int> ib, int c);

	list<int> getID_b() const;
	int getID_l() const;
	int getCount() const;

	void setID_l(int IDl);
	void setID_b(list<int> IDb);
	void setCount(int counts);

};

#endif
