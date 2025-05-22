#include "MainMenuFunk.h"

void mainMenu() {
    cout << "\nMain Menu:\n";
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}


void mainMenuHandler() {
    list<User> users;
    loadListFromFile(users, "users.txt");

    int choice;
    do {
        mainMenu();
        cin >> choice;
        if (choice == 1) {
            string email, password;
            cout << "Enter email: ";
            cin >> email;
            cout << "Enter password: ";
            cin >> password;

            bool emailFound = false;
            for (const auto& u : users) {
                if (u.getEmail() == email) {
                    emailFound = true;
                    if (u.getPassword() == password) {
                        cout << "Login successful.\n";
                        string type = u.getRole().getType();
                        if (type == "admin")
                            adminMenuHandler(users);
                        else if (type == "librarian")
                            librarianMenuHandler();
                        else
                            userMenuHandler(u);
                    }
                    else {
                        cout << "Incorrect password.\n";
                    }
                    break; // Вийти з циклу після перевірки
                }
            }

            if (!emailFound) {
                cout << "Email not found.\n";
            }
        }
        else if (choice == 2) {
            User newUser;
            try {
                newUser.read(cin);
                users.push_back(newUser);
                saveListToFile(users, "users.txt");
                cout << "Registration successful.\n";
            }
            catch (const exception& e) {
                cerr << "Registration failed: " << e.what() << endl;
            }
        }
    } while (choice != 0);
}
