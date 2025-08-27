#pragma once
#include <iostream>
#include <string>

// ��� ������ Ŭ������ ����ؾ� �� �������̽�
class Item {
public:
    virtual void PrintInfo() const = 0;
    virtual int GetPrice() const = 0;
    virtual ~Item() = default;
};