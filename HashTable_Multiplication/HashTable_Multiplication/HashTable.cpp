#include <iostream>
#include <string>

#include "HashTable.h"

HashTable::Item::Item()
{
	hits = 0;
	name = "empty";
	prev = nullptr;
	next = nullptr;
}

HashTable::HashTable()
{
	// initialize pointers to buckets
	for (int i = 0; i < table_size; ++i)
	{
		Table[i] = new Item;
	}
}

int HashTable::Hash(int hits)
{
	int hash = (hits * hash_s) >> (word_size - hash_p);
	int index = std::abs(hash % table_size);

	return index;
}

// create Item from data and add it to Table
void HashTable::AddItem(int hits, std::string name)
{
	int index = Hash(hits);

	if (Table[index]->name == "empty")
	{
		Table[index]->hits = hits;
		Table[index]->name = name;
	}
	else
	{
		Item* ptr = Table[index];
		Item* n = new Item;
		n->hits = hits;
		n->name = name;
		n->next = nullptr;
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		ptr->next = n;
		n->prev = ptr;
	}
}

void HashTable::AddItem(Item* ptr)
{
	int index = Hash(ptr->hits);

	if (Table[index]->name == "empty")
	{
		Table[index] = ptr;
	}
	else
	{
		Item* temp = Table[index];
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->prev = temp;
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
		std::cout << Table[i]->hits << std::endl;
		std::cout << Table[i]->name << std::endl;
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
			std::cout << ptr->hits << std::endl;
			std::cout << ptr->name << std::endl;
			std::cout << "--------------\n";
			ptr = ptr->next;
		}
	}
}

void HashTable::FindName(int hits)
{
	int index = Hash(hits);
	bool foundName = false;
	std::string name;

	Item* ptr = Table[index];
	while (ptr)
	{
		if (ptr->hits == hits)
		{
			foundName = true;
			name = ptr->name;
		}
		ptr = ptr->next;
	}

	if (foundName)
	{
		std::cout << "Name " << name << " had " << hits << " hits.\n";
	}
	else
	{
		std::cout << "No one has " << hits << " hits in the Hash Table\n";
	}
}

void HashTable::RemoveItem(Item* ptr)
{
	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
}