#include "Library.h"

int Library::getID_library() const {
    return id_library;
}

string Library::getLibrary_name() const {
    return library_name;
}

string Library::getLibrary_address() const {
    return library_address;
}

int Library::getLoan_duration() const {
    return loan_duration;
}
