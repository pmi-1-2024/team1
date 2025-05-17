#include "Order.h"
Order::Order() : ID_order(0), ID_user(0), start_day(0) {}
Order::Order(int IDo, list<int> IDb, int IDu, int sd) 
	: ID_order(IDo), ID_book(IDb), ID_user(IDu), start_day(sd) {}

int Order::getID_order() const { return ID_order; }
list<int> Order::getID_book() const { return ID_book; }
int Order::getID_user() const { return ID_user; }
int Order::getStart_day() const { return start_day; }

void Order::setID_order(int IDo) { ID_order = IDo; }
void Order::setID_book(list<int> IDb) { ID_book = IDb; }
void Order::setID_user(int IDu) { ID_user = IDu; }
void Order::setStart_day(int sd) { start_day = sd; }

void Order::print(ostream& os) const {
	os << "Order ID: " << ID_order << ", User ID: " << ID_user << ", Start Day: " << start_day << endl;
	os << "Book IDs: ";
	for (const auto& id : ID_book) {
		os << id << " ";
	}
	os << endl;
}
void Order::read(istream& is) {
	ID_book.clear();
	is >> ID_order >> ID_user >> start_day;
	int num_books;
	is >> num_books;
	for (int i = 0; i < num_books; ++i) {
		int book_id;
		is >> book_id;
		ID_book.push_back(book_id);
	}
}

ostream& operator<<(ostream& os, const Order& o) {
	os << o.ID_order << " " << o.ID_user << " " << o.start_day << " ";
	os << o.ID_book.size() << " ";
	for (int id : o.ID_book) {
		os << id << " ";
	}
	os << endl;
	return os;
}
istream& operator>>(istream& is, Order& o) {
	o.read(is);
	return is;
}