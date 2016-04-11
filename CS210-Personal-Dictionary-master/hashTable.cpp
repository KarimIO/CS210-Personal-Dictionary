// File:hashTable.cpp
// hashTable Class implementation file
#ifndef HASH_TABLE_CPP
#define HASH_TABLE_CPP
#include "hashTable.h"
#include <iostream>

// Constructor with argument, size is nelements, default is 11
template <class keyType, class dataType>
hashTable<keyType, dataType>::hashTable(bool Accessible, const keyType &k, int nelements)
{
	// Set Maximum Size
	MaxSize = nelements;

	// Allocate memory
	T = new slot[nelements];

	// Set Table
	emptyTable(k);

	// Set Accessible
	accessible = Accessible;
}

// Destructor
template <class keyType, class dataType>
hashTable<keyType, dataType>::~hashTable()
{
	//Free allocated memory
	delete[] T;
}
// Empty all slots
template <class keyType, class dataType>
void hashTable<keyType, dataType>::emptyTable(const keyType &k)
{
	//Set the Empty value
	Empty = k;

	//Loop to put the Empty value in all table slots
	for (int i = 0; i < MaxSize; i++) {
		T[i].key = Empty;
	}

	//Initialize index to a slot h
	h = -1;

	//Initialize current size csize
	csize = 0;
}

// return True if table is Empty
template <class keyType, class dataType>
bool hashTable<keyType, dataType>::tableIsEmpty() const
{
	//Test current size  (csize)
	return csize <= 0;
}

// return True if table is full
template <class keyType, class dataType>
bool hashTable<keyType, dataType>::tableIsFull() const
{
	//Test current size   (csize)
	return csize >= MaxSize;
}

// insert key and data at a hashed slot
template <class keyType, class dataType>
bool hashTable<keyType, dataType>::insert(const keyType &k, const dataType &d)
{
	if (!tableIsFull()) {
		h = hash(k);
		while (T[h].key != Empty) {
			h = (h + 1) % MaxSize;
		}
		T[h].key = k;
		T[h].data = d;
		return true;
	}
	else
		return false;
}

// Search the table for the slot that matches key. 
// If found, return True, set current position to slot
template <class keyType, class dataType>
bool hashTable<keyType, dataType>::search(const keyType &k) {
	if (tableIsEmpty()) {
		h = hash(k);
		int start = h;
		while (true) {
			if (T[h].key == k)
				return true;

			h = (h + 1) % MaxSize;

			if (h == start)
				return false;
		}
	}
	else
		return false;
}

template <class keyType, class dataType>
bool hashTable<keyType, dataType>::get(const keyType &k, dataType &d) {
	if (!accessible) {
		std::cout << "Inaccessible Hash Table - Attemped Access" << std::endl;
		return false;
	}

	if (!search(k)) {
		return false;
	}

	d = T[h].data;

	return true;
}

// Private Hashing Function
template <class keyType, class dataType>
int hashTable<keyType, dataType>::hash(const keyType &k) const {
	int hashed = 0;
	for (size_t i = 0; i < k.size(); i++) {
		hashed += int(k[i]);
	}
	return (hashed % MaxSize);
}

#endif