#include "LibraryBooks.h"

LibraryBooks::LibraryBooks() : ID_l(0), ID_b(0), count(0) {}

LibraryBooks::LibraryBooks(int il, list<int> ib, int c) : ID_l(il), ID_b(ib), count(c) {}

list<int> LibraryBooks::getID_b() const { return ID_b; }
int LibraryBooks::getID_l() const { return ID_l; }
int LibraryBooks::getCount() const { return count; }

void LibraryBooks::setID_l(int IDl) { ID_l = IDl; }
void LibraryBooks::setID_b(list<int> IDb) { ID_b = IDb; }
void LibraryBooks::setCount(int counts) { count = counts; }
