#ifndef EBOOK_H
#define EBOOK_H
#include "Books.h"

class Ebook : public Books {
private:
	int ID_format;
public:
	Ebook();
	Ebook(int IDb, string bn, int ye, list<Author> aut, Publisher pub, int pc, list<Genre> gen, int IDf);

	int getID_format() const;
	void setID_format(int IDf);

	void print(ostream& os) const;
	void read(istream& is);
	friend ostream& operator<<(ostream& os, const Ebook& eb);
	friend istream& operator>>(istream& is, Ebook& eb);
};

#endif
