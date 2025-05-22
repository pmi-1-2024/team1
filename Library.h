#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
using namespace std;

class Library
{
private: 
	//(ID, назва, адреса, тривалість)
	int id_library;
	string library_name;
	string address;
	int duration;
public:
	Library();
	Library(int idl, string ln, string ad, int d);

	int getId_library() const;
	string getLibrary_name() const;
	string getAddress() const;
	int getDuration() const;

	void setId_library(int idl);
	void setLibrary_name(string ln);
	void setAddress(string ad);
	void setDuration(int d);

	void print(ostream& os) const;
	void read(istream& is);
	friend ostream& operator<<(ostream& os, const Library& lib);
	friend istream& operator>>(istream& is, Library& lib);
	
};


#endif