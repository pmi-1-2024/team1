#include "PaperBooks.h"

PaperBooks::PaperBooks() : Books(){}
PaperBooks::PaperBooks(int IDb, string bn, int ye, list<Author> aut, Publisher pub, int pc, list<Genre> gen)
	: Books(IDb, bn, ye, aut, pub, pc, gen) {
}
void PaperBooks::print(ostream& os) const {
	Books::print(os);
	os << "Format ID: " << endl;
}
void PaperBooks::read(istream& is) {
	Books::read(is);
}
ostream& operator<<(ostream& os, const PaperBooks& eb) {
	eb.print(os);
	return os;
}
istream& operator>>(istream& is, PaperBooks& eb) {
	eb.read(is);
	return is;
}