#include "Weapon.h"
#include <iostream>

Weapon::Weapon(std::string name, int price)
    : name_(name), price_(price) {
}

void Weapon::PrintInfo() const {
    std::cout << "[�̸�: " << name_ << ", ����: " << price_ << "G]" << std::endl;
}

int Weapon::GetPrice() const {
    return price_;
}