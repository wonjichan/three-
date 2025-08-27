#pragma once
#include <iostream>
#include <string>

// 모든 아이템 클래스가 상속해야 할 인터페이스
class Item {
public:
    virtual void PrintInfo() const = 0;
    virtual int GetPrice() const = 0;
    virtual ~Item() = default;
};