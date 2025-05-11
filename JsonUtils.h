#ifndef JSONUTILS_H
#define JSONUTILS_H

#include "User.h"
#include "Books.h"
#include "Library.h"
#include "Order.h"
#include <vector>

// ===== USERS =====
void saveUsersToJSON(const std::vector<User>& users);
std::vector<User> loadUsersFromJSON();

// ===== BOOKS =====
void saveBooksToJSON(const std::vector<Books>& books);
std::vector<Books> loadBooksFromJSON();

// ===== LIBRARIES =====
void saveLibrariesToJSON(const std::vector<Library>& libraries);
std::vector<Library> loadLibrariesFromJSON();

// ===== ORDERS =====
void saveOrdersToJSON(const std::vector<Order>& orders);
std::vector<Order> loadOrdersFromJSON();

#endif
