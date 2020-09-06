#pragma once

#include <iostream>
#include <string>

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable
{
private:
	static const int table_size = 10;	// # of buckets

	struct Item
	{
		std::string name;
		std::string drink;
		Item* next;			// singly linked list for collision management
	};

	Item* Table[table_size];

public:
	HashTable();	
	int Hash(std::string name);			// division method with sum of ASCII values
	void AddItem(std::string name, std::string drink);
	int NumberOfItemsInIndex(int index);
	void PrintTable();					// prints first Item in a bucket (if Item exists), and # chained Items
	void PrintItemsInIndex(int index);	// prints the Items in a given bucket
	void FindDrink(std::string);
	void RemoveItem(std::string);
};


#endif // HASHTABLE_H