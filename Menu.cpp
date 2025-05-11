#include "Menu.h"
#include "UserMenu.h"
#include "AdminMenu.h"
#include "LibrarianMenu.h"
#include "JsonUtils.h"
#include <iostream>
using namespace std;

// Пошук користувача за email та паролем
User* login(vector<User>& users) {
    string email, password;
    cout << "Email: ";
    cin >> email;
    cout << "Password: ";
    cin >> password;

    for (auto& user : users) {
        if (user.getEmail() == email && user.getPassword() == password) {
            cout << "Login successful.\n";
            return &user;
        }
    }

    cout << "Invalid email or password.\n";
    return nullptr;
}

// Реєстрація нового користувача
void registerUser(vector<User>& users) {
    string name, surname, email, password;
    int id = 10000000 + rand() % 90000000;

    cout << "First name: ";
    cin >> name;
    cout << "Last name: ";
    cin >> surname;
    cout << "Email: ";
    cin >> email;
    cout << "Password: ";
    cin >> password;

    User newUser(name, surname, id, email, password);
    users.push_back(newUser);
    saveUsersToJSON(users);
    cout << "Registered successfully. Your ID: " << id << endl;
}

// Меню входу та реєстрації
void showMainMenu(vector<User>& users) {
    int choice;

    while (true) {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Log in\n";
        cout << "2. Register\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            User* currentUser = login(users);
            if (currentUser) {
                int role = currentUser->getRole().getRole();
                if (role == 0) {
                    roleMenuUser(currentUser);
                }
                else if (role == 1) {
                    roleMenuAdmin(currentUser, users);
                }
                else if (role == 2) {
                    roleMenuLibrarian();
                }
            }
        }
        else if (choice == 2) {
            registerUser(users);
        }
        else if (choice == 0) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
}
