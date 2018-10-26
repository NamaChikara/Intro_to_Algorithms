#include <iostream>
#include <string>

#include "HashTable_OpenAddressing.h"

int main()
{
	HashTable myhash;
	myhash.HashInsert("Zack", 22);
	myhash.HashInsert("Matt", 19);
	myhash.HashInsert("Glen", 22);
	myhash.HashInsert("Trevor", 22);
	myhash.HashInsert("Lindsey", 23);
	myhash.HashInsert("Liz", 22);
	myhash.HashInsert("Grandpa", 81);
	myhash.HashInsert("Queen Elizabeth", 86);
	myhash.HashInsert("Personable A", 24);
	myhash.HashInsert("Personable B", 66);
	myhash.HashInsert("Born Jan1 2017", 2);

	myhash.PrintTable();

	std::cin.get();
	return 0;
}