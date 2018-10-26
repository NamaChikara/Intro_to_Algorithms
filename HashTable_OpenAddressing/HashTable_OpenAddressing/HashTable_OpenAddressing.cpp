#include "HashTable_OpenAddressing.h"

Item::Item()
	: name{ "empty" }, age{ 0 } {};

Item::Item(std::string& name, int age)
	: name{ name }, age{ age } {};

void Item::delete_item()
{
	name = "deleted";
	age = 0;
}

std::ostream& operator<<(std::ostream& os, Item toprint)
{
	os << "Name: " << toprint.name << ", age: " << toprint.age;
	return os;
}

unsigned long HashTable::aux_hash(const char *str)
{
	unsigned long hash = 5381;
	int c;
	while (c = *str++)
	{
		hash = ((hash << 5) + hash) + c;	// hash * 33 + c 
	}
	return hash;
}

int HashTable::hash(const std::string& key, int probe)
{
	return (aux_hash(key.c_str()) + probe) % table_size;
}

void HashTable::HashInsert(std::string name, int age)
{
	int index = 0;
	for (int i = 0; i < table_size; ++i)
	{
		index = hash(name, i);
		if (Table[index].name == "empty" || Table[index].name == "deleted")
		{
			Table[index] = Item(name, age);
			return;
		}
	}
	std::cout << "Could not insert " << name << ", the table is full." << std::endl;
}

void HashTable::PrintTable()
{
	for (int i = 0; i < table_size; ++i)
	{
		if (Table[i].name != "empty" && Table[i].name != "deleted")
		{
			std::cout << "---------------\n";
			std::cout << "Index " << i << " contains:" << std::endl;
			std::cout << Table[i] << std::endl;
			std::cout << "---------------\n";
		}
	}
}