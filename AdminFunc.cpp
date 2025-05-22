#include "AdminFunc.h"

void adminMenu() {
     cout << "\nAdmin Menu:\n";
     cout << "1. Change User Role\n";
     cout << "2. Add Library\n";
     cout << "3. Edit Library\n";
     cout << "4. Delete Library\n";
     cout << "0. Logout\n";
     cout << "Choice: ";
}

void adminMenuHandler(list<User>& users) {
    list<Library> libraries;
    loadListFromFile(libraries, "libraries.txt");

    int choice;
    do {
        adminMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            cout << "Enter User ID to change role: ";
            cin >> id;

            bool found = false;
            for (auto& u : users) {
                if (u.getID() == id) {
                    string newRole;
                    cout << "Enter new role (user/admin/librarian): ";
                    cin >> newRole;
                    try {
                        u.changeRoleType(newRole);
                        cout << "Role updated successfully.\n";
                        found = true;
                    }
                    catch (const exception& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;
                }
            }
            if (!found) {
                cout << "User with ID " << id << " not found.\n";
            }
            saveListToFile(users, "users.txt");
            break;
        }

        case 2: {
            Library newLib;
            try {
				newLib.read(cin); 
                libraries.push_back(newLib);
                saveListToFile(libraries, "libraries.txt");
                cout << "Library added successfully.\n";
            }
            catch (const exception& e) {
                cerr << "Error reading library: " << e.what() << endl;
            }
            break;
        }

        case 3: {
            int id;
            cout << "Enter Library ID to edit: ";
            cin >> id;

            bool found = false;
            for (auto& l : libraries) {
                if (l.getId_library() == id) {
                    cout << "Enter new data for the library:\n";
                    try {
                        l.read(cin);
                        cout << "Library updated successfully.\n";
                        found = true;
                    }
                    catch (const exception& e) {
                        cerr << "Error reading library: " << e.what() << endl;
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Library with ID " << id << " not found.\n";
            }
            saveListToFile(libraries, "libraries.txt");
            break;
        }

        case 4: {
            int id;
            cout << "Enter Library ID to delete: ";
            cin >> id;

            size_t oldSize = libraries.size();
            libraries.remove_if([id](const Library& l) {
                return l.getId_library() == id;
                });

            if (libraries.size() < oldSize) {
                cout << "Library deleted successfully.\n";
            }
            else {
                cout << "Library with ID " << id << " not found.\n";
            }
            saveListToFile(libraries, "libraries.txt");
            break;
        }

        case 0:
            cout << "Logging out...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }

    } while (choice != 0);
}
