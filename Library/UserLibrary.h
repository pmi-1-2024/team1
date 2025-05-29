#ifndef USERLIBRARY_H
#define USERLIBRARY_H
#include "User.h"
#include "Library.h"
class UserLibrary
{
private:
    User user;
    Library library;
    int userID;
    int libraryID;
    Role role;
public:
	UserLibrary();
	UserLibrary(const User& u, const Library& l, const Role& r);

	User getUser() const;
	Library getLibrary() const;
	int getUserID() const;
	int getLibraryID() const;
	Role getRole() const;

	bool isUserInLibrary(int uID, int libID) const;
	bool hasRole(const std::string& roleType) const;
};

#endif
