#include "User.h"
#include "validators.h"

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
string User::getSurname() const { return surname; }
int User::getID() const { return user_id; }
string User::getEmail() const { return email; }
string User::getPassword() const { return password; }
Role User::getRole() const { return role; }

void User::setName(string n) { name = n; }
void User::setSurname(string s) { surname = s; }
void User::setId(int id) { user_id = id; }
void User::setEmail(string em) {
	if (isValidEmail(email))
		email = em;
	else
		throw invalid_argument("Invalid email: must look like this: example@example.domain");
}
void User::setPassword(string pw) {
	if (isValidPassword(password))
		password = pw;
	else
		throw invalid_argument("Invalid password: Password must contain at least one lowercase letter, one uppercase letter, one digit, one special character, and be at least 8 characters long.");
}
void User::setRole(const Role& r) { role = r; }

void User::changeRoleType(const string& newRoleType) {
	if (newRoleType == "user") {
		role.setType("user");
		role.setRole_id(0);
	}
	else if (newRoleType == "librarian") {
		role.setType("librarian");
		role.setRole_id(1);
	}
	else if (newRoleType == "admin") {
		role.setType("admin");
		role.setRole_id(2);
	}
	else {
		throw invalid_argument("Invalid role type. Allowed: user, admin, librarian");
	}
}

int User::loadLastUserID(const string& filename) {
	ifstream file(filename);
	int id = 10000000;
	if (file >> id) return id;
	return 10000000;
}

void User::saveLastUserID(const string& filename, int id) {
	ofstream file(filename, ios::trunc);
	file << id;
}

void User::print(ostream& os) const {
	os << "Name: " << name << ", Surname: " << surname << ", ID: " << user_id
		<< ", Email: " << email << ", Password: " << password
		<< ", Role: " << role.getType() << endl;
}
void User::read(istream& is) {
	cout << "Name: ";
	is >> name;

	cout << "Surname: ";
	is >> surname;

	int lastID = loadLastUserID("last_user_id.txt");
	user_id = lastID + 1;
	saveLastUserID("last_user_id.txt", user_id);

	cout << "Email: ";
	is >> email;
	if (!isValidEmail(email)) {
		throw invalid_argument("Invalid email (must contain '@')");
	}

	cout << "Password: ";
	is >> password;
	if (!isValidPassword(password)) {
		throw invalid_argument("Password must be exactly 8 digits");
	}

	role = Role();
}
ostream& operator<<(ostream& os, const User& u) {
	os << u.name << " " << u.surname << " " << u.user_id << " "
		<< u.email << " " << u.password << " " << u.role.getRole_id() << " " << u.role.getType() << endl;
	return os;
}
istream& operator>>(istream& is, User& u) {
	is >> u.name >> u.surname >> u.user_id >> u.email >> u.password;
	is >> u.role;
	return is;
}