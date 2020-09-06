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

HashTable::HashTable(std::string hash_type)
	: hash_type{ hash_type } {};

unsigned long HashTable::aux_hash(const char *str)
{
	unsigned long hash = 5381;
	int c = 0;

	while (c = *str++)
	{
		hash = ((hash << 5) + hash) + c;	// hash * 33 + c 
	}

	return hash;
}

unsigned long HashTable::double_hash(const char *str)
{
	unsigned long hash = 0;
	int c = 0;

	while (c = *str++)
	{
		hash = c + (hash << 6) + (hash << 16) - hash;
	}

	if (hash % 2 == 0)
	{
		++hash;
	}

	return hash;
}

int HashTable::hash(const std::string& key, int probe)
{
	if (hash_type == "quadratic_probe")
		// if table_size is a power of 2, quadratic function (i^2 + i)/2 will visit
		//  each bucket
	{
		return (aux_hash(key.c_str()) + (probe*probe + probe) / 2) % table_size;
	}
	if (hash_type == "double_hash")
		// if table_size is a power of 2, this will visit each bucket since double_hash
		//  is designed to return an odd value
	{
		return (aux_hash(key.c_str()) + probe * double_hash(key.c_str())) % table_size;
	}
	else  
		// in particular, if hash_type == "linear_probe"
	{
		return (aux_hash(key.c_str()) + probe) % table_size;
	}
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

int HashTable::HashSearch(std::string name)
{
	int index = 0;
	for (int i = 0; i < table_size; ++i)
	{
		index = hash(name, i);
		if (Table[index].name == name)
		{
			return index;
		}
		if (Table[index].name == "empty")
		{
			return -1;
		}
	}
	return -1;
}

int HashTable::HashDelete(std::string name)
{
	int index = 0;
	for (int i = 0; i < table_size; ++i)
	{
		index = hash(name, i);
		if (Table[index].name == name)
		{
			Table[index].delete_item();
			return index;
		}
		if (Table[index].name == "empty")
		{
			return -1;
		}
	}
	return -1;
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

void HashTable::PrintIndex(int index)
{
	if (0 <= index && index < table_size)
	{
		std::cout << "---------------\n";
		std::cout << "Index " << index << " contains:" << std::endl;
		std::cout << Table[index] << std::endl;
		std::cout << "---------------\n";
	}
	else
	{
		std::cout << "Index " << index << " is not in the hash table." << std::endl;
	}
}