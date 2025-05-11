#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
using namespace std;

class Library {
private:
    int id_library;
    string library_name;
    string library_address;
    int loan_duration;

public:
    Library() = default;

    Library(int id, const string& name, const string& address, int duration)
        : id_library(id), library_name(name), library_address(address), loan_duration(duration) {}

    int getID_library() const;
    string getLibrary_name() const;
    string getLibrary_address() const;
    int getLoan_duration() const;
};

#endif
