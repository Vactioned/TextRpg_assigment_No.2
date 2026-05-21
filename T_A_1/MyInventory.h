#ifndef MYINVENTORY_H_
#define MYINVENTORY_H_

#include <iostream>
#include <format>
#include <algorithm>

#include "Item.h"

inline bool compareByPrice(const Item& a, const Item& b)
{
	return a.price < b.price;
}

template<typename T>

class MyInventory
{

private:
	T* pItems_;
	int capacity_;
	int size_;

public:

	MyInventory(int capacity)
		: capacity_(capacity) 
	{
		size_ = 0;
		pItems_ = new T[capacity_];
	}
	
	MyInventory(const MyInventory& other)
	{
		size_ = other.size_;
		capacity_ = other.capacity_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; ++i)
		{
			pItems_[i] = other.pItems_[i];
		}
	}

	MyInventory& operator=(const MyInventory& other)
	{
		if (this == &other)
		{
			return *this;
		}
		size_ = other.size_;
		capacity_ = other.capacity_;
		delete[] pItems_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; ++i)
		{
			pItems_[i] = other.pItems_[i];
		}
		return *this;
	}

	~MyInventory() 
	{
		delete[] pItems_;
	}

	int getsize()
	{
		return size_;
	}
	int getCapacity()
	{
		return capacity_;
	}
	
	void additem(T item)
	{
		if (size_ < capacity_)
		{
			pItems_[size_] = item;
			size_++;
		}

		else
		{
			std::cout << std::format("Inventory become x 2");
			Resize(capacity_ * 2);
			pItems_[size_] = item;
			size_++;
		}
	}

	void removeitemlast()
	{
		if (size_ > 0)
		{
			size_ -= 1;
		}
	
		else
		{
			std::cout << std::format("Inventory is Empty!");
		}
	}
	
	void printallitems()
	{

		std::cout << std::format("\n[ Inventory ({}/{}) ]\n", size_, capacity_);

		for (int i = 0; i < size_; ++i)
		{
			std::cout << std::format("{}. ", i + 1);
			pItems_[i].PrintInfo();
			std::cout << "\n";
		}
	}

	void Resize(int newCap)
	{
		T* newinv = new T[newCap];

		for (int i = 0; i < size_; ++i)
		{
			newinv[i] = pItems_[i];
		}

		delete[] pItems_;

		pItems_ = newinv;

		capacity_ = newCap;

	}

	void SortItems()
	{
		std::sort(pItems_, pItems_ + size_, compareByPrice);
	}

};

#endif