#ifndef FUNC_H
#define FUNC_H
//Завдання
//Адмін
//    1. CRUD(додати, читати, виправити, видалити) бібліотеки
//    2. Змінювати ролі для юзерів
//Бібліотекар
//    1. CRUD книг
//    2. CRUD library_book(якщо додавати існуючу вибити помилку)
//    3. CRUD замовлення

#include <fstream>
#include <sstream>
#include <list>

#include "PaperBooks.h"
#include "EBook.h"
#include "Order.h"
#include "Library.h"
#include "User.h"
using namespace std;

template <typename T>
void saveListToFile(const list<T>& items, const string& filename);

template <typename T>
void loadListFromFile(list<T>& items, const string& filename);


void saveBooksToFile(const list<Books*>& items, const string& filename);
void loadBooksFromFile(list<Books*>& items, const string& filename);

#endif
