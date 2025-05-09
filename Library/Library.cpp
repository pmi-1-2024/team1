#include "Library.h"
Library::Library(int idl, string ln, string ad, int d)
	: id_library(idl), library_name(ln), address(ad), duration(d) {
}
Library::Library() : id_library(0), library_name(" "),address(" "), duration (0) {

}
int Library::getId_library() const { return id_library;}
string Library::getLibrary_name() const { return library_name; }
string Library::getAddress() const { return address; }
int Library::getDuration() const {
	return duration;
}

void Library::setId_library(string idl) { id_library = idl; }
void Library::setLibrary_name(string ln) { library_name = ln; }
void Library::setAddress(int ad) { address = ad; }
void Library::setDuration(string d) { destination = d; }

