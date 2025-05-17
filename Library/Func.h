#ifndef FUNC_H
#define FUNC_H
/*��������
//1. �������� *.csv/json/xml(���������� � �����, ������� �)
//2. ���� ��������� ���������/���������
//����
//    1. CRUD(������, ������, ���������, ��������) ��������
//    2. �������� ��� ��� �����
//����������
//    1. CRUD ����
//    2. CRUD library_book(���� �������� ������� ������ �������)
//    3. CRUD ����������
//����������
//   1. ����������� ����� (������)
//   2. ����������� � ���� ��������� �� �*/

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
