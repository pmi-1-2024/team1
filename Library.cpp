#include "Library.h"

Library::Library() : id_library(0), library_name(" "), address(" "), duration(0) {}
Library::Library(int idl, string ln, string ad, int d)
	: id_library(idl), library_name(ln), address(ad), duration(d) {
}

int Library::getId_library() const { return id_library;}
string Library::getLibrary_name() const { return library_name; }
string Library::getAddress() const { return address; }
int Library::getDuration() const { return duration; }

void Library::setId_library(int idl) { id_library = idl; }
void Library::setLibrary_name(string ln) { library_name = ln; }
void Library::setAddress(string ad) { address = ad; }
void Library::setDuration(int d) { duration = d; }

void Library::print(ostream& os) const {
	os << "Library ID: " << id_library << ", Name: " << library_name
		<< ", Address: " << address << ", Duration: " << duration << endl;
}
void Library::read(istream& is) {
	cout << "Enter Library ID: ";
	is >> id_library;
	cout << "Enter Library Name: ";
	is >> library_name;
	cout << "Enter Address: ";
	is >> address;
	cout << "Enter Duration: ";
	is >> duration;
}

ostream& operator<<(ostream& os, const Library& lib) {
	os << lib.id_library << " " << lib.library_name << " "
		<< lib.address << " " << lib.duration << endl;
	return os;
}
istream& operator>>(istream& is, Library& lib) {
	is >> lib.id_library >> lib.library_name >> lib.address >> lib.duration;
	return is;
}


