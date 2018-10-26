#include <iostream>
#include <string>

#include "HashTable_OpenAddressing.h"

int main()
{
	HashTable myhash;
	myhash.HashInsert("Zack", 22);
	myhash.PrintTable();
	std::cin.get();
	return 0;
}