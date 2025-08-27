#pragma once
#include "Item.h"
#include <string>

class Weapon : public Item {
private:
    std::string name_;
    int price_;
public:
    Weapon(std::string name = "", int price = 0);
    void PrintInfo() const override;
    int GetPrice() const override;
};