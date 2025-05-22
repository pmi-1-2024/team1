#ifndef BOOKSSTRUCTS_h
#define BOOKSSTRUCTS_h
#include <iostream>
using namespace std;

struct Author {
	//(ID, name, surname)
	int ID_autor;
	string author_name;
	string surname;
	Author(int id = 0, string n = " ", string s = " ") : ID_autor(id), author_name(n), surname(s) {}
	void read(istream& is) {
		cout << "ID: ";
		is >> ID_autor;
		cout << "Name: ";
		is >> author_name;
		cout << "Surname: ";
		is >> surname;
	}
	friend ostream& operator<<(ostream& os, const Author& a) {
		os << a.ID_autor << " " << a.author_name << " " << a.surname;
		return os;
	}
	friend istream& operator>>(istream& is, Author& a) {
		is >> a.ID_autor >> a.author_name >> a.surname;
		return is;
	}
};
struct Publisher {
	//(ID, name, address)
	int ID_publish;
	string publish_name;
	string address;
	Publisher(int id = 0, string n = " ", string a = " ") : ID_publish(id), publish_name(n), address(a) {}
	void read(istream& is) {
		cout << "ID: ";
		is >> ID_publish;
		cout << "Name: ";
		is >> publish_name;
		cout << "Address: ";
		is >> address;
	}
	friend ostream& operator<<(ostream& os, const Publisher& p) {
		os << p.ID_publish << " " << p.publish_name << " " << p.address;
		return os;
	}
	friend istream& operator>>(istream& is, Publisher& p) {
		is >> p.ID_publish >> p.publish_name >> p.address;
		return is;
	}
};
struct Genre {
	//(ID, name)
	int ID_genre;
	string genre_name;
	Genre(int id = 0, string n = " ") : ID_genre(id), genre_name(n) {}
	void read(istream& is) {
		cout << "ID: ";
		is >> ID_genre;
		cout << "Name: ";
		is >> genre_name;
	}
	friend ostream& operator<<(ostream& os, const Genre& g) {
		os << g.ID_genre << " " << g.genre_name;
		return os;
	}
	friend istream& operator>>(istream& is, Genre& g) {
		is >> g.ID_genre >> g.genre_name;
		return is;
	}
};

#endif
