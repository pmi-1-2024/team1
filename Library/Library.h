#ifndef LIBRARY_H
#define LIBRARY_H
class Library
{
private: 
	//(ID, назва, адреса, тривалість)
	int id_library;
	string library_name;
	string address;
	int duration;
public:
	Library(int idl, string ln, string ad, int d);
	Library();
	int getId_library() const;
	string getLibrary_name() const;
	string getAddress() const;
	int getDuration() const;

	void setId_library(string idl);
	void setLibrary_name(string ln);
	void setAddress(int ad);
	void setDuration(string d);
	
};


#endif