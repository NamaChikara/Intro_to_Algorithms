#include <iostream>
#include <string>

#include "HashTable.h"

HashTable::HashTable()
{
	for (int i = 0; i < table_size; ++i)
	{
		Table[i] = new Item;
		Table[i]->name = "empty";
		Table[i]->drink = "empty";
		Table[i]->next = nullptr;
	}
}

int HashTable::Hash(std::string key)
{
	int hash = 0;
	int index = 0;

	for (int i = 0; i < key.length(); ++i)
	{
		hash += (int)key[i];
	}

	index = hash % table_size;

	return index;
}

void HashTable::AddItem(std::string name, std::string drink)
{
	int index = Hash(name);

	if (Table[index]->name == "empty")
	{
		Table[index]->name = name;
		Table[index]->drink = drink;
	}
	else
	{
		Item* ptr = Table[index];
		Item* n = new Item;
		n->name = name;
		n->drink = drink;
		n->next = nullptr;
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		ptr->next = n;
	}
}

int HashTable::NumberOfItemsInIndex(int index)
{
	int count = 0;

	if (Table[index]->name == "empty")
	{
		return count;
	}
	else
	{
		++count;
		Item* ptr = Table[index];
		while (ptr->next != nullptr)
		{
			++count;
			ptr = ptr->next;
		}
		return count;
	}
}

void HashTable::PrintTable()
{
	int number = 0;
	for (int i = 0; i < table_size; ++i)
	{
		number = NumberOfItemsInIndex(i);
		std::cout << "--------------\n";
		std::cout << "index = " << i << std::endl;
		std::cout << Table[i]->name << std::endl;
		std::cout << Table[i]->drink << std::endl;
		std::cout << "# of items = " << number << std::endl;
		std::cout << "--------------\n";
	}
}

void HashTable::PrintItemsInIndex(int index)
{
	Item* ptr = Table[index];
	if (ptr->name == "empty")
	{
		std::cout << "index " << index << " is empty\n";
	}
	else
	{
		std::cout << "index " << index << " contains the following "
			<< "items\n";
		while (ptr != nullptr)
		{
			std::cout << "--------------\n";
			std::cout << ptr->name << std::endl;
			std::cout << ptr->drink << std::endl;
			std::cout << "--------------\n";
			ptr = ptr->next;
		}
	}
}

void HashTable::FindDrink(std::string name)
{
	int index = Hash(name);
	bool foundName = false;
	std::string drink;

	Item* ptr = Table[index];
	while (ptr)
	{
		if (ptr->name == name)
		{
			foundName = true;
			drink = ptr->drink;
		}
		ptr = ptr->next;
	}

	if (foundName)
	{
		std::cout << "Favorite drink = " << drink << std::endl;
	}
	else
	{
		std::cout << name << " is not found in the Hash Table\n";
	}
}

void HashTable::RemoveItem(std::string name)
{
	int index = Hash(name);

	//Item* delPtr;
	Item* ptr1;
	Item* ptr2;

	// Case 0: bucket it empty
	if (Table[index]->name == "empty" && Table[index]->drink == "empty")
	{
		std::cout << name << " was not found in Hash Table\n";
	}

	// Case 1: only 1 item contained in bucket and that item has matching name
	else if (Table[index]->name == name && Table[index]->next == nullptr)
	{
		Table[index]->name = "empty";
		Table[index]->drink = "empty";
		std::cout << name << " was the only entry in index " << index << std::endl;
	}
	
	// Case 2: match is located in the first item in the bucket, but there are
	//  more items in the bucket
	else if (Table[index]->name == name && Table[index]->next)
	{
		Table[index] = Table[index]->next;
		std::cout << name << " was the first entry in index " << index << std::endl;
	}

	// Case 3: bucket contains items but first item is not a match
	// Case 3.1: no match
	// Case 3.2: match is found
	else
	{
		ptr1 = Table[index];
		ptr2 = Table[index]->next;
		while (ptr2)
		{
			if (ptr2->name == name)
			{
				ptr1->next = ptr2->next;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
	}
}