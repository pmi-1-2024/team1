#include "Menu.h"
#include "User.h"
#include <vector>

int main() {
    std::vector<User> users; // ������ ������������ ���� ���������� �������� Menu
    showMainMenu(users);     // ������ ��������� ����
    return 0;
}
