#include <iostream>
#include <string>

#include "HashTable_OpenAddressing.h"

int main()
{
	HashTable myhash("double_hash");

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

	int gpa_index = myhash.HashSearch("Grandpa");
	myhash.PrintIndex(gpa_index);

	int delete_index = myhash.HashDelete("Zack");
	std::cout << "Zack was deleted from index " 
		<< delete_index << std::endl;
	myhash.PrintIndex(delete_index);

	delete_index = myhash.HashDelete("BBBBB");
	std::cout << "BBBBB was deleted from index "
		<< delete_index << std::endl;
	myhash.PrintIndex(delete_index);

	std::cin.get();
	return 0;
}