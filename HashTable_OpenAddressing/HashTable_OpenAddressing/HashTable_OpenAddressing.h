// This HashTable class used open addressing to manage collisions.
//  It selects a probing method based on the value of std::string hash_type
//  (whose default value is "linear_probe").  Both linear and quadratic probing
//  ("quadratic_probe") use the djb2 algorithm (k = 33) (described in 
//  http://www.cse.yorku.ca/~oz/hash.html) as their auxiliary hash function.
//  Double hashing ("double_hash") uses the additional algorithm sdbm (same source),
//  modified to always produce odd output so that the whole table is checked if
//  table_size is a power of 2.

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
	static const int table_size = 16;	// power of 2 for optimal quadratic_probing
	Item Table[table_size];
	std::string hash_type;		// the hash function checks the value of this string
								//  to determine which type of probe to use (linear 
								//  probe is the default)
	
	// djb2 algorithm (k = 33) described in http://www.cse.yorku.ca/~oz/hash.html
	unsigned long aux_hash(const char *str);

	// sdbm algorithm described in http://www.cse.yorku.ca/~oz/hash.html
	//  modified to always produce odd output for use in double hashing
	//  (since table_size = 2^p, this ensures the whole table is checked)
	unsigned long double_hash(const char *str);
	
	// linear probe using auxiliary hash function aux_hash
	int hash(const std::string& key, int probe);

public:
	HashTable(std::string hash_type = "linear_probe");
	void HashInsert(std::string name, int age);
	int HashSearch(std::string name);
	int HashDelete(std::string name);
	void PrintTable();
	void PrintIndex(int index);
};



#endif // 
