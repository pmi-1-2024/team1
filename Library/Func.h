#ifndef FUNC_H
#define FUNC_H
/*Завдання
//1. підтримка *.csv/json/xml(записувати в файли, зчитати з)
//2. Мати можливість реєстрація/логування
//Адмін
//    1. CRUD(додати, читати, виправити, видалити) бібліотеки
//    2. Змінювати ролі для юзерів
//Бібліотекар
//    1. CRUD книг
//    2. CRUD library_book(якщо додавати існуючу вибити помилку)
//    3. CRUD замовлення
//Користувач
//   1. Переглядати книги (історія)
//   2. Переглядати в яких бібліотеках він є*/

#include <fstream>
#include <sstream>
#include <list>

#include "Books.h"
#include "Order.h"
#include "Library.h"
#include "User.h"
using namespace std;

template <typename T>
void saveListToFile(const list<T>& items, const string& filename);

template <typename T>
void loadListFromFile(list<T>& items, const string& filename);

void mainMenu();
void userMenu(const User& user);
void adminMenu();
void librarianMenu();
#endif
