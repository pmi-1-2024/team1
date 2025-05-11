#include "User.h"

User::User() : name(""), surname(""), id(0), email(""), password("") {
    role.setRole(RoleType::User);
}

User::User(string n, string s, int i, string em, string pw)
    : name(n), surname(s), id(i), email(em), password(pw) {
    role.setRole(RoleType::User);
}

string User::getName() const { return name; }
string User::getSurname() const { return surname; }
int User::getID() const { return id; }
string User::getEmail() const { return email; }
string User::getPassword() const { return password; }

// Повертає значення ролі (int)
int User::getRole() const { return role.getRole(); }

// Повертає посилання на об'єкт ролі (для setRole())
Role& User::getRole() { return role; }

void User::setName(string n) { name = n; }
void User::setSurname(string s) { surname = s; }
void User::setID(int i) { id = i; }
void User::setEmail(string em) { email = em; }
void User::setPassword(string pw) { password = pw; }
void User::setRole(int r) { role.setRole(r); }
