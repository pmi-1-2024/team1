#include "AdminMenu.h"
#include "JsonUtils.h"
#include "Library.h"
#include <iostream>
#include <vector>

using namespace std;

// 📚 Додавання бібліотеки
void addLibrary() {
    int id = 1000 + rand() % 9000;
    string name, address;
    int duration;

    cout << "\n=== Add Library ===\n";
    cout << "Name: ";
    cin >> name;
    cout << "Address: ";
    cin >> address;
    cout << "Loan duration (days): ";
    cin >> duration;

    vector<Library> libs = loadLibrariesFromJSON();
    libs.emplace_back(id, name, address, duration);
    saveLibrariesToJSON(libs);

    cout << "Library added successfully!\n";
}

// 👥 Зміна ролі користувача
void changeUserRole(vector<User>& allUsers) {
    int uid, newRole;
    cout << "\n=== Change User Role ===\n";
    cout << "Enter User ID: ";
    cin >> uid;
    cout << "Enter New Role (0 - User, 1 - Admin, 2 - Librarian): ";
    cin >> newRole;

    for (auto& user : allUsers) {
        if (user.getID() == uid) {
            user.setRole(newRole);
            saveUsersToJSON(allUsers);
            cout << "Role updated.\n";
            return;
        }
    }

    cout << "User ID not found.\n";
}

// ⚙ Меню адміністратора
void roleMenuAdmin(User* currentUser, vector<User>& allUsers) {
    int choice;
    do {
        cout << "\n=== ADMIN MENU ===\n";
        cout << "1. Add Library\n";
        cout << "2. Change User Role\n";
        cout << "0. Logout\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addLibrary(); break;
        case 2: changeUserRole(allUsers); break;
        case 0: break;
        default: cout << "Invalid option.\n";
        }
    } while (choice != 0);
}
