#ifndef ORDER_H
#define ORDER_H

#include <list>
using namespace std;

class Order {
private:
    int ID_order;
    int ID_book;
    int ID_user;
    int start_day;

public:
    Order(); // дефолтний
    Order(int IDo, int IDb, int IDu, int sd); // повний
    Order(int IDo, int IDu, int sd);          // спрощений, без ID книги

    int getID_order() const;
    int getID_book() const;
    int getID_user() const;
    int getStart_day() const;

    void setID_order(int IDo);
    void setID_book(int IDb);
    void setID_user(int IDu);
    void setStart_day(int sd);
};

#endif
