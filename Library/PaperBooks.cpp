#include "PaperBooks.h"

PaperBooks::PaperBooks() : Books() {}
PaperBooks::PaperBooks(int IDb, string bn, int ye, list<Author> aut, Publisher pub, int pc, list<Genre> gen)
	: Books(IDb, bn, ye, aut, pub, pc, gen) {
}
int PaperBooks::getID_format() const { return ID_format; }
void PaperBooks::setID_format(int IDf) { ID_format = IDf; }
void PaperBooks::print(ostream& os, const Library& lib) const {
	Books::print(os, lib);
	os << "Format ID: " << ID_format << endl;
}
void PaperBooks::read(istream& is) {
	Books::read(is);
	cout << "Enter Format ID: ";
	is >> ID_format;
}
ostream& operator<<(ostream& os, const PaperBooks& eb) {
	os << static_cast<const Books&>(eb);
	os << eb.ID_format << endl;
	return os;
}
istream& operator>>(istream& is, PaperBooks& eb) {
	eb.read(is);
	return is;
}