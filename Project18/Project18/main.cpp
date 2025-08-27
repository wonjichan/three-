#include "Inventory.h"
#include "Weapon.h"

int main() {
    Inventory<Weapon> inv;

    inv.AddItem(Weapon("단검", 50));
    inv.AddItem(Weapon("활", 100));
    inv.AddItem(Weapon("장검", 150));

    std::cout << "\n=== 전체 아이템 ===" << std::endl;
    inv.PrintAllItems();

    std::cout << "\n=== 정렬 후 ===" << std::endl;
    inv.SortItems();
    inv.PrintAllItems();

    std::cout << "\n=== 마지막 아이템 제거 ===" << std::endl;
    inv.RemoveLastItem();
    inv.PrintAllItems();

    std::cout << "\n=== 복사 생성자 테스트 ===" << std::endl;
    Inventory<Weapon> copied(inv);
    copied.PrintAllItems();

    std::cout << "\n=== 대입 함수 테스트 ===" << std::endl;
    Inventory<Weapon> assigned;
    assigned.Assign(inv);
    assigned.PrintAllItems();

    return 0;
}