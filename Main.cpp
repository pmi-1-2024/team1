#include "Menu.h"
#include "User.h"
#include <vector>

int main() {
    std::vector<User> users; // список користувачів буде заповнений всередині Menu
    showMainMenu(users);     // запуск головного меню
    return 0;
}
