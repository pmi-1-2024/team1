#include "User.h"

bool User::checkEmail(const string& em) const {
	return em.find('@') != string::npos;
}

bool User::checkPassword(const string& pw) const {
	if (pw.length() != 8) return false;
	for (char c : pw)
		if (!isdigit(c))
			return false;
	return true;
}

User::User() : name(" "), surname(" "), user_id(0), email(" "), password(" "), role() {}

User::User(string n, string s, int id, string em, string pw, Role r)
	: name(n), surname(s), user_id(id), email(em), password(pw), role(r) {}

string User::getName() const { return name; }
string User:: getSurname() const { return surname; }
int User:: getID() const { return user_id; }
string User:: getEmail() const { return email; }
string User:: getPassword() const { return password; }
Role User::getRole() const { return role; }

void User::setName(string n) { name = n; }
void User::setSurname(string s) { surname = s; }
void User::setId(int id) { user_id = id; }
void User::setEmail(string em) { 
	if (checkEmail(em))
		email = em;
	else
		throw invalid_argument("Invalid email: must contain '@'");
}
void User::setPassword(string pw) {
	if (checkPassword(pw))
		password = pw;
	else
		throw invalid_argument("Invalid password: must be exactly 8 digits");
}
void User::setRole(const Role& r) { role = r; }

void User::changeRoleType(const string& newRoleType) {
	if (newRoleType == "user" || newRoleType == "admin" || newRoleType == "librarian") {
		role.setType(newRoleType);
	}
	else {
		throw invalid_argument("Invalid role type. Allowed: user, admin, librarian");
	}
}

bool User::login(const string& em, const string& pw) const {
	return email == em && password == pw;
}

void User::print(ostream& os) const {
	os << "Name: " << name << ", Surname: " << surname << ", ID: " << user_id
		<< ", Email: " << email << ", Password: " << password
		<< ", Role: " << role.getType() << endl;
}
void User::read(istream& is) {
	is >> name >> surname >> user_id >> email >> password;
	role.read(is);
}
ostream& operator<<(ostream& os, const User& u) {
	os << u.name << " " << u.surname << " " << u.user_id << " "
		<< u.email << " " << u.password << " " << u.role.getRole_id() << " " << u.role.getType() << endl;
	return os;
}
istream& operator>>(istream& is, User& u) {
	u.read(is);
	return is;
}