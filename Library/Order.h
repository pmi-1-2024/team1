#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <list>
#include <fstream>
using namespace std;
class Order
{
private:
	int ID_order;
	list<int> ID_book;
	int ID_user;
	int start_day;
public:
	Order();
	Order(int IDo, list<int> IDb, int IDu, int sd);

	int getID_order() const;
	list<int> getID_book() const;
	int getID_user() const;
	int getStart_day() const;

	void setID_order(int IDo);
	void setID_book(list<int> IDb);
	void setID_user(int IDu);
	void setStart_day(int sd);

	int loadLastOrderID(const string& filename);
	void saveLastOrderID(const string& filename, int id);

	void print(ostream& os) const;
	void read(istream& is, int userID);
	friend ostream& operator<<(ostream& os, const Order& o);
	friend istream& operator>>(istream& is, Order& o);
};

#endif
