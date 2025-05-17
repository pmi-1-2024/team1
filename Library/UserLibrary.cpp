#include "UserLibrary.h"

UserLibrary::UserLibrary() : userID(0), libraryID(0), role() {}
UserLibrary::UserLibrary(const User& u, const Library& l, const Role& r)
	: user(u), library(l), userID(u.getID()), libraryID(l.getId_library()), role(r) {}

User UserLibrary::getUser() const { return user; }
Library UserLibrary::getLibrary() const { return library; }
int UserLibrary::getUserID() const { return userID; }
int UserLibrary::getLibraryID() const { return libraryID; }
Role UserLibrary::getRole() const { return role; }

bool UserLibrary::isUserInLibrary(int uID, int libID) const {
	return (userID == uID && libraryID == libID);
}
bool UserLibrary::hasRole(const std::string& roleType) const {
	return (role.getType() == roleType);
}

