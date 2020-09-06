#include <iostream>
#include <string>

#include "HashTable.h"

int main()
{
	HashTable myhash;
	
	myhash.AddItem("Zack", "Pfreim");
	myhash.AddItem("Dad", "Coffee");
	myhash.AddItem("Matt", "CBD");
	myhash.AddItem("Glen", "Cider");
	myhash.AddItem("Trevor", "Kombucha");
	myhash.AddItem("Madison", "Smoothie");
	myhash.AddItem("Lizzie", "Wine");
	myhash.AddItem("Lindsey", "Cortado");
	myhash.AddItem("Ian", "Mikes Hard");
	myhash.AddItem("Marcus", "Bush Lite");
	myhash.AddItem("Josh", "Diet Coke");
	myhash.AddItem("Grandma", "Tea");

	myhash.PrintTable();
	myhash.PrintItemsInIndex(4);
	myhash.RemoveItem("Josh");
	myhash.PrintItemsInIndex(4);

	std::cin.get();

	return 0;
}