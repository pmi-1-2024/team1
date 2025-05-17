#ifndef PAPERBOOKS_H
#define PAPERBOOKS_H
#include "Books.h"

class PaperBooks : public Books {
public:
	PaperBooks();
	PaperBooks(int IDb, string bn, int ye, list<Author> aut, Publisher pub, int pc, list<Genre> gen);
	void print(ostream& os) const override;
	void read(istream& is) override;
	friend ostream& operator<<(ostream& os, const PaperBooks& pb);
	friend istream& operator>>(istream& is, PaperBooks& pb);

};

#endif
