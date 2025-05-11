#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Role.h"
using namespace std;

class User {
private:
    string name;
    string surname;
    int id;
    string email;
    string password;
    Role role;

public:
    User();  // Конструктор за замовчуванням
    User(string n, string s, int id, string em, string pw);  // Повний конструктор

    // Гетери
    string getName() const;
    string getSurname() const;
    int getID() const;
    string getEmail() const;
    string getPassword() const;
    int getRole() const;
    Role& getRole(); // Для редагування ролі

    // Сетери
    void setName(string n);
    void setSurname(string s);
    void setID(int id);
    void setEmail(string em);
    void setPassword(string pw);
    void setRole(int r);
};

#endif
