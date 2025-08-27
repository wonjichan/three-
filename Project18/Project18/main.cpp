#include "Inventory.h"
#include "Weapon.h"

int main() {
    Inventory<Weapon> inv;

    inv.AddItem(Weapon("�ܰ�", 50));
    inv.AddItem(Weapon("Ȱ", 100));
    inv.AddItem(Weapon("���", 150));

    std::cout << "\n=== ��ü ������ ===" << std::endl;
    inv.PrintAllItems();

    std::cout << "\n=== ���� �� ===" << std::endl;
    inv.SortItems();
    inv.PrintAllItems();

    std::cout << "\n=== ������ ������ ���� ===" << std::endl;
    inv.RemoveLastItem();
    inv.PrintAllItems();

    std::cout << "\n=== ���� ������ �׽�Ʈ ===" << std::endl;
    Inventory<Weapon> copied(inv);
    copied.PrintAllItems();

    std::cout << "\n=== ���� �Լ� �׽�Ʈ ===" << std::endl;
    Inventory<Weapon> assigned;
    assigned.Assign(inv);
    assigned.PrintAllItems();

    return 0;
}