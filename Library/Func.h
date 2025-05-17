#ifndef FUNC_H
#define FUNC_H
//��������
//����
//    1. CRUD(������, ������, ���������, ��������) ��������
//    2. �������� ��� ��� �����
//����������
//    1. CRUD ����
//    2. CRUD library_book(���� �������� ������� ������ �������)
//    3. CRUD ����������

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
