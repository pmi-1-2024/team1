#include "Role.h"

Role::Role() : role_id(0), type("user") {}
Role::Role(int rol_id, string t) : role_id(rol_id), type(t) {}

int Role::getRole_id() const { return role_id; }
string Role::getType() const { return type; }

void Role::setRole_id(int rol_id) { role_id = rol_id; }
void Role::setType(string t) {
	if (t != "user" && t != "admin" && t != "librarian") {
		throw invalid_argument("Invalid role type. Allowed: user, admin, librarian");
	}
	type = t;
}

void Role::print(ostream& os) const {
	os << "Role ID: " << role_id << ", Type: " << type << endl;
}
void Role::read(istream& is) {
	is >> role_id >> type;
	if (type != "user" && type != "admin" && type != "librarian") {
		throw invalid_argument("Invalid role type. Allowed: user, admin, librarian");
	}
}

ostream& operator<<(ostream& os, const Role& r) {
	os << r.role_id << " " << r.type;
	return os;
}
istream& operator>>(istream& is, Role& r) {
	is >> r.role_id;
	string t;
	is >> t;
	r.setType(t); // тепер відбувається перевірка
	return is;
}