#ifndef ROLE_H
#define ROLE_H

struct RoleType {
    static const int User = 0;
    static const int Admin = 1;
    static const int Librarian = 2;
};

class Role {
private:
    int userId;
    int role = RoleType::User; // äåôîëòíà ðîëü — êîðèñòóâà÷
public:
    void setRole(int r) { role = r; }
    int getRole() const { return role; }
};



#endif
