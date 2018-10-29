#include <iostream>

#include "BinarySearchTree.h"

int main()
{
	Element* first = new Element(10);
	Element* second = new Element(8);
	first->left = second;
	second->parent = first;
	Tree mytree{ first };
	Element* result = mytree.minimum();
	std::cout << result->key << std::endl;
	Tree mytree2;
	mytree2.insert(first);
	std::cout << mytree2.root->key << std::endl;
	std::cin.get();
}