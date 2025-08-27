#pragma once

#include <iostream>

template <typename T>
class Inventory {
private:
    T* pItems_;
    int capacity_;
    int size_;

public:
    // �ʼ� ���
    Inventory(int capacity = 10);
    ~Inventory();
    void AddItem(const T& item);
    void RemoveLastItem();
    int GetSize() const;
    int GetCapacity() const;
    void PrintAllItems() const;

    // ���� ���
    Inventory(const Inventory<T>& other);
    void Assign(const Inventory<T>& other);
    void Resize(int newCapacity);
    void SortItems();
};

// ���ø� ���� ����
#include "Inventory.tpp"