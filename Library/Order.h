#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <list>
using namespace std;
class Order
{
	//(ID, ID_book, ID_user, start_day(дата коли книжка була взята))
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
};

#endif
