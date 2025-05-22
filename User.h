#ifndef USER_H
#define USER_H
#include "Role.h"
#include <fstream>
class User
{
private:
	string name;
	string surname;
	int user_id;
	string email;
	string password;
	Role role;

	bool checkEmail(const string& em) const;
	bool checkPassword(const string& pw) const;
public:
	User();
	User(string n, string s, int id, string em, string pw, Role r = Role());
	string getName() const;
	string getSurname() const;
	int getID() const;
	string getEmail() const;
	string getPassword() const;
	Role getRole() const;

	void setName(string n);
	void setSurname(string s);
	void setId(int id);
	void setEmail(string em);
	void setPassword(string pw);
	void setRole(const Role& r);
	
	void changeRoleType(const string& newRoleType);

	int loadLastUserID(const string& filename);
	void saveLastUserID(const string& filename, int id);

	void print(ostream& os) const;
	void read(istream& is);

	friend ostream& operator<<(ostream& os, const User& u);
	friend istream& operator>>(istream& is, User& u);
};

#endif
