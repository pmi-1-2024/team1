#include "User.h"

User::User(string n, string s, int id, string em, string pw)
	: name(n), surname(s), id(id), email(em), password(pw) {
	role.userId = id;
}
User::User(): name(" "), surname(" "), id(0), email(" "), password(" ") {
	role.userId = 0;
	role.role = RoleType::User;
}
string User::getName() const { return name; }
string User:: getSurname() const { return surname; }
int User:: getID() const { return ID; }
string User:: getEmail() const { return email; }
string User:: getPassword() const { return password; }

void User::setName(string n) { name = n; }
void User::setSurname(string s) { surname = s; }
void User:: setId(int id) {ID = id }
void User::setEmail(string em) { email = em; }
void User::setPassword(string pw) { password = pw; }