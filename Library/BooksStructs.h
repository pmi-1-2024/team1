#ifndef BOOKSSTRUCTS_h
#define BOOKSSTRUCTS_h
#include <iostream>
using namespace std;

struct Author {
	//(ID, name, surname)
	int ID_autor;
	string author_name;
	string surname;
};
struct Publisher {
	//(ID, name, address)
	int ID_publish;
	string publish_name;
	string address;
};
struct Genre {
	//(ID, name)
	int ID_genre;
	string genre_name;
};

#endif
