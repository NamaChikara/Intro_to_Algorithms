#include <iostream>
#include "HashTable.h";

int main()
{
	HashTable myhash;

	myhash.AddItem(4256, "Pete Rose");
	myhash.AddItem(4186, "Ty Cobb");
	myhash.AddItem(3771, "Hank Aaron");
	myhash.AddItem(3630, "Stan Musial");
	myhash.AddItem(3514, "Tris Speaker");

	HashTable::Item* derek_jeter = new HashTable::Item;
	derek_jeter->hits = 3465;
	derek_jeter->name = "Derek Jeter";
	derek_jeter->prev = nullptr;
	derek_jeter->next = nullptr;
	myhash.AddItem(derek_jeter);

	myhash.AddItem(3435, "Cap Anson");
	myhash.AddItem(3420, "Honus Wagner");
	myhash.AddItem(3419, "Carl Yastrzemski");
	myhash.AddItem(3319, "Paul Molitor");
	myhash.AddItem(3315, "Eddie Collins");
	myhash.AddItem(3283, "Willie Mays");
	myhash.AddItem(3255, "Eddie Murray");
	myhash.AddItem(3243, "Nap Lajoie");
	myhash.AddItem(3184, "Cal Ripken");

	myhash.PrintTable();

	myhash.PrintItemsInIndex(1);

	myhash.RemoveItem(derek_jeter);

	myhash.PrintItemsInIndex(1);

	std::cin.get();
}