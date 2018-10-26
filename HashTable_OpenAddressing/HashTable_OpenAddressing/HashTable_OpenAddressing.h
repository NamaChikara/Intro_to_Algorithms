// This HashTable class used open addressing to manage collisions.
//  It uses linear probing with auxiliary hash function djb2 algorithm 
//  (k = 33) described in http://www.cse.yorku.ca/~oz/hash.html

#pragma once

#include <iostream>
#include <string>

#ifndef HASHTABLE_OPENADDRESSING_H
#define HASHTABLE_OPENADDRESSING_H

struct Item {
	Item();
	Item(std::string& name, int age);
	void delete_item();
	std::string name;
	int age;
};

std::ostream& operator<<(std::ostream& os, Item toprint);

class HashTable {

private:
	static const int table_size = 100;
	Item Table[table_size];
	
	// djb2 algorithm (k = 33) described in http://www.cse.yorku.ca/~oz/hash.html
	unsigned long aux_hash(const char *str);
	
	// linear probe using auxiliary hash function aux_hash
	int hash(const std::string& key, int probe);

public:
	void HashInsert(std::string name, int age);
	int HashSearch(std::string name);
	void PrintTable();
	void PrintIndex(int index);
};



#endif // 
