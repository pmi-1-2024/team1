#include "EBook.h"

Ebook::Ebook() : ID_format(0) {}
Ebook::Ebook(int IDb, string bn, int ye, list<Author> aut, Publisher pub, int pc, list<Genre> gen, int IDf)
	: Books(IDb, bn, ye, aut, pub, pc, gen), ID_format(IDf) {
}
int Ebook::getID_format() const { return ID_format; }
void Ebook::setID_format(int IDf) { ID_format = IDf; }

void Ebook::print(ostream& os, const Library& lib) const {
	Books::print(os, lib);
	os << "Format ID: " << ID_format << endl;
}
void Ebook::read(istream& is) {
	Books::read(is);
	cout << "Enter Format ID: ";
	is >> ID_format;
}
ostream& operator<<(ostream& os, const Ebook& eb) {
	os << static_cast<const Books&>(eb);
	os << eb.ID_format << endl;
	return os;
}
istream& operator>>(istream& is, Ebook& eb) {
	eb.read(is);
	return is;
}