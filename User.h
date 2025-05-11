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
    User();  // ����������� �� �������������
    User(string n, string s, int id, string em, string pw);  // ������ �����������

    // ������
    string getName() const;
    string getSurname() const;
    int getID() const;
    string getEmail() const;
    string getPassword() const;
    int getRole() const;
    Role& getRole(); // ��� ����������� ���

    // ������
    void setName(string n);
    void setSurname(string s);
    void setID(int id);
    void setEmail(string em);
    void setPassword(string pw);
    void setRole(int r);
};

#endif
