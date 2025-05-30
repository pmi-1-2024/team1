#ifndef PAPERBOOKS_H
#define PAPERBOOKS_H
#include "Books.h"

class PaperBooks : public Books {
private:
	int ID_format;
public:
	PaperBooks();
	PaperBooks(int IDb, string bn, int ye, list<Author> aut, Publisher pub, int pc, list<Genre> gen);
	int getID_format() const;
	void setID_format(int IDf);
	void print(ostream& os, const Library& lib) const override;
	void read(istream& is) override;
	friend ostream& operator<<(ostream& os, const PaperBooks& pb);
	friend istream& operator>>(istream& is, PaperBooks& pb);

};

#endif
