#pragma once
#include <algorithm>
#include "Item.h"
// 가격 비교 함수 (Item 기반)
bool compareItemsByPrice(const Item& a, const Item& b) {
    return a.GetPrice() < b.GetPrice();
}

// 생성자
template <typename T>
Inventory<T>::Inventory(int capacity) {
    if (capacity <= 0)
        capacity = 1;
    capacity_ = capacity;
    size_ = 0;
    pItems_ = new T[capacity_];
}

// 소멸자
template <typename T>
Inventory<T>::~Inventory() {
    delete[] pItems_;
    pItems_ = nullptr;
}

// 복사 생성자
template <typename T>
Inventory<T>::Inventory(const Inventory<T>& other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    pItems_ = new T[capacity_];
    for (int i = 0; i < size_; ++i) {
        pItems_[i] = other.pItems_[i];
    }
    std::cout << "인벤토리 복사 완료" << std::endl;
}

// 대입 함수
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

    std::cout << "인벤토리 대입 완료" << std::endl;
}

// 아이템 추가
template <typename T>
void Inventory<T>::AddItem(const T& item) {
    if (size_ >= capacity_) {
        std::cout << "인벤토리가 꽉 찼습니다! 크기를 2배로 확장합니다." << std::endl;
        Resize(capacity_ * 2);
    }
    pItems_[size_++] = item;
}

// 아이템 제거
template <typename T>
void Inventory<T>::RemoveLastItem() {
    if (size_ == 0) {
        std::cout << "인벤토리가 비어있습니다." << std::endl;
        return;
    }
    --size_;
}

// 현재 아이템 개수 반환
template <typename T>
int Inventory<T>::GetSize() const {
    return size_;
}

// 인벤토리 용량 반환
template <typename T>
int Inventory<T>::GetCapacity() const {
    return capacity_;
}

// 전체 아이템 출력
template <typename T>
void Inventory<T>::PrintAllItems() const {
    if (size_ == 0) {
        std::cout << "(비어있음)" << std::endl;
        return;
    }

    for (int i = 0; i < size_; ++i) {
        pItems_[i].PrintInfo();
    }
}

// 인벤토리 크기 조정
template <typename T>
void Inventory<T>::Resize(int newCapacity) {
    if (newCapacity < size_) {
        std::cout << "새 용량은 현재 아이템 수보다 작을 수 없습니다." << std::endl;
        return;
    }

    T* newItems = new T[newCapacity];
    for (int i = 0; i < size_; ++i) {
        newItems[i] = pItems_[i];
    }

    delete[] pItems_;
    pItems_ = newItems;
    capacity_ = newCapacity;

    std::cout << "인벤토리 용량을 " << newCapacity << "으로 조정했습니다." << std::endl;
}

// 아이템 정렬 (가격 기준)
template <typename T>
void Inventory<T>::SortItems() {
    std::sort(pItems_, pItems_ + size_, compareItemsByPrice);
    std::cout << "아이템을 가격 오름차순으로 정렬했습니다." << std::endl;
}