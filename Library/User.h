#ifndef USER_H
#define USER_H
#include "Role.h"
class User
{
	//(ім'я, прізвище, ID(8-значне число), email, пароль).
private:
	string name;
	string surname;
	int id;
	string email;
	string password;
	Role role;
public:
	User(string n, string s, int id, string em, string pw); 
	User();
	string getName() const;
	string getSurname() const;
	int getID() const;
	string getEmail() const;
	string getPassword() const;

	void setName(string n);
	void setSurname(string s);
	void setID(int id);
	void setEmail(string em);
	void setPassword(string pw);
	};

#endif
