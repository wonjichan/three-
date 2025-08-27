#pragma once

#include <iostream>

template <typename T>
class Inventory {
private:
    T* pItems_;
    int capacity_;
    int size_;

public:
    // 필수 기능
    Inventory(int capacity = 10);
    ~Inventory();
    void AddItem(const T& item);
    void RemoveLastItem();
    int GetSize() const;
    int GetCapacity() const;
    void PrintAllItems() const;

    // 도전 기능
    Inventory(const Inventory<T>& other);
    void Assign(const Inventory<T>& other);
    void Resize(int newCapacity);
    void SortItems();
};

// 템플릿 구현 포함
#include "Inventory.tpp"