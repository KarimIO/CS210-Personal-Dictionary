// File: hashTable.h
// Definition of Hash Table Template Class

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

// Specification of the class

template <class keyType, class dataType>

class hashTable
{
public:

	// Member Functions
	hashTable(bool Accessible, const keyType &k, int nelements);	// Constructor
	~hashTable();													// Destructor

	// Functions Prototype Definitions
	void emptyTable(const keyType &);
	bool tableIsEmpty() const;
	bool tableIsFull() const;
	bool insert(const keyType &, const dataType &);
	bool search(const keyType &);
	bool get(const keyType &k, dataType &d);

private:

	// Slot Class
	class slot
	{
	public:
		keyType key; 		// key 
		dataType data;		// Data
	}; // end of class slot declaration

	slot *T;							// Pointer to Storage Array
	int h;								// Index to a slot
	int MaxSize, csize;					// Maximum and Current Sizes
	keyType Empty;						// empty symbol
	bool accessible;
										// Private Member function
	int hash(const keyType &) const;
};
#endif // HASH_TABLE_H
#include "hashTable.cpp"