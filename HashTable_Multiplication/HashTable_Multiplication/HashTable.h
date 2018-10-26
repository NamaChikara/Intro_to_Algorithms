// This HashTable class used doubly linked lists to manage collisions.
//  Its hash function is the multiplication method (described below during
//  initialization of constants).

#pragma once

#include <iostream>
#include <string>
#include <cmath>

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable
{
public:
	struct Item
	{
		Item();
		int hits;			// number of hits in a season (the key)
		std::string name;
		Item* prev;			// doubly linked list for collision management
		Item* next;
	};

private:
	static const int table_size = 10;	// # of buckets
	// h(k) = 2^p(kA mod 1), where A = s / 2^w where w is processor word size
	//  It is suggested to choose s so A is close to (sqrt(5)-1)/2.
	//  If w = 30, then s = 2654435769. To compute h(k) we simply do 
	//	h(k) = (k * s) >> (word size - p)
	static const long hash_s = 2654435769;
	static const int word_size = 32;
	static const int hash_p = 14;

	Item* Table[table_size];

public:
	HashTable();
	int Hash(int hits);			// multiplication method
	void AddItem(int hits, std::string name);
	void AddItem(Item* ptr);
	int NumberOfItemsInIndex(int index);
	void PrintTable();					// prints first Item in a bucket (if Item exists), and # chained Items
	void PrintItemsInIndex(int index);	// prints the Items in a given bucket
	void FindName(int hits);	
	void RemoveItem(Item*);
};


#endif // HASHTABLE_H