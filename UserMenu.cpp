#include "UserMenu.h"
#include "JsonUtils.h"
#include "Order.h"
#include "Books.h"
#include <iostream>
#include <vector>

using namespace std;

// 📋 Перегляд замовлень користувача
void showUserOrders(int userId) {
    vector<Order> orders = loadOrdersFromJSON();

    cout << "\nYour Orders:\n";
    for (const auto& ord : orders) {
        if (ord.getID_user() == userId) {
            cout << "Order ID: " << ord.getID_order()
                << ", Book ID: " << ord.getID_book()
                << ", Start Day: " << ord.getStart_day() << endl;
        }
    }
}

// 📚 Оформлення нового замовлення
void borrowBook(int userId) {
    vector<Books> books = loadBooksFromJSON();
    vector<Order> orders = loadOrdersFromJSON();

    cout << "\nAvailable Books:\n";
    for (const auto& b : books) {
        cout << "ID: " << b.getID_book()
            << ", Name: " << b.getBook_name()
            << ", Year: " << b.getYear() << endl;
    }

    int bookId;
    cout << "Enter Book ID to borrow: ";
    cin >> bookId;

    int newOrderId = orders.empty() ? 1 : orders.back().getID_order() + 1;
    int startDay = 20240510; // заглушка, дата видачі

    orders.emplace_back(newOrderId, bookId, userId, startDay);
    saveOrdersToJSON(orders);

    cout << "Book borrowed successfully.\n";
}

// 👤 Меню користувача
void roleMenuUser(User* user) {
    int choice;
    do {
        cout << "\n=== USER MENU ===\n";
        cout << "1. View Your Orders\n";
        cout << "2. Borrow Book\n";
        cout << "0. Logout\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            showUserOrders(user->getID());
            break;
        case 2:
            borrowBook(user->getID());
            break;
        case 0:
            break;
        default:
            cout << "Invalid option.\n";
        }
    } while (choice != 0);
}
