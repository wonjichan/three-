#pragma once
#include <algorithm>
#include "Item.h"
// ���� �� �Լ� (Item ���)
bool compareItemsByPrice(const Item& a, const Item& b) {
    return a.GetPrice() < b.GetPrice();
}

// ������
template <typename T>
Inventory<T>::Inventory(int capacity) {
    if (capacity <= 0)
        capacity = 1;
    capacity_ = capacity;
    size_ = 0;
    pItems_ = new T[capacity_];
}

// �Ҹ���
template <typename T>
Inventory<T>::~Inventory() {
    delete[] pItems_;
    pItems_ = nullptr;
}

// ���� ������
template <typename T>
Inventory<T>::Inventory(const Inventory<T>& other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    pItems_ = new T[capacity_];
    for (int i = 0; i < size_; ++i) {
        pItems_[i] = other.pItems_[i];
    }
    std::cout << "�κ��丮 ���� �Ϸ�" << std::endl;
}

// ���� �Լ�
template <typename T>
void Inventory<T>::Assign(const Inventory<T>& other) {
    if (this == &other) return;

    delete[] pItems_;

    capacity_ = other.capacity_;
    size_ = other.size_;
    pItems_ = new T[capacity_];
    for (int i = 0; i < size_; ++i) {
        pItems_[i] = other.pItems_[i];
    }

    std::cout << "�κ��丮 ���� �Ϸ�" << std::endl;
}

// ������ �߰�
template <typename T>
void Inventory<T>::AddItem(const T& item) {
    if (size_ >= capacity_) {
        std::cout << "�κ��丮�� �� á���ϴ�! ũ�⸦ 2��� Ȯ���մϴ�." << std::endl;
        Resize(capacity_ * 2);
    }
    pItems_[size_++] = item;
}

// ������ ����
template <typename T>
void Inventory<T>::RemoveLastItem() {
    if (size_ == 0) {
        std::cout << "�κ��丮�� ����ֽ��ϴ�." << std::endl;
        return;
    }
    --size_;
}

// ���� ������ ���� ��ȯ
template <typename T>
int Inventory<T>::GetSize() const {
    return size_;
}

// �κ��丮 �뷮 ��ȯ
template <typename T>
int Inventory<T>::GetCapacity() const {
    return capacity_;
}

// ��ü ������ ���
template <typename T>
void Inventory<T>::PrintAllItems() const {
    if (size_ == 0) {
        std::cout << "(�������)" << std::endl;
        return;
    }

    for (int i = 0; i < size_; ++i) {
        pItems_[i].PrintInfo();
    }
}

// �κ��丮 ũ�� ����
template <typename T>
void Inventory<T>::Resize(int newCapacity) {
    if (newCapacity < size_) {
        std::cout << "�� �뷮�� ���� ������ ������ ���� �� �����ϴ�." << std::endl;
        return;
    }

    T* newItems = new T[newCapacity];
    for (int i = 0; i < size_; ++i) {
        newItems[i] = pItems_[i];
    }

    delete[] pItems_;
    pItems_ = newItems;
    capacity_ = newCapacity;

    std::cout << "�κ��丮 �뷮�� " << newCapacity << "���� �����߽��ϴ�." << std::endl;
}

// ������ ���� (���� ����)
template <typename T>
void Inventory<T>::SortItems() {
    std::sort(pItems_, pItems_ + size_, compareItemsByPrice);
    std::cout << "�������� ���� ������������ �����߽��ϴ�." << std::endl;
}