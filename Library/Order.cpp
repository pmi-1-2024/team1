#include "Order.h"
Order::Order() : ID_order(0), ID_book(0), ID_user(0), start_day(0) {}
Order::Order(int IDo, list<int> IDb, int IDu, int sd) : ID_order(IDo), ID_book(IDb), ID_user(IDu), start_day(sd) {}

int Order::getID_order() const { return ID_order; }
list<int> Order::getID_book() const { return ID_book; }
int Order::getID_user() const { return ID_user; }
int Order::getStart_day() const { return start_day; }

void Order::setID_order(int IDo) { ID_order = IDo; }
void Order::setID_book(list<int> IDb) { ID_book = IDb; }
void Order::setID_user(int IDu) { ID_user = IDu; }
void Order::setStart_day(int sd) { start_day = sd; }