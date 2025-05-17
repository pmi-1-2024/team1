#ifndef ROLE_H
#define ROLE_H
#include <iostream>
#include <string>
using namespace std;

class Role {
private:
	int role_id;
	string type;
public:
	Role();
	Role(int rol_id, string t);
	int getRole_id() const;
	string getType() const;
	void setRole_id(int rol_id);
	void setType(string t);

	void print(ostream& os) const;
	void read(istream& is);

	friend ostream& operator<<(ostream& os, const Role& role);
	friend istream& operator>>(istream& is, Role& role);
};
#endif
