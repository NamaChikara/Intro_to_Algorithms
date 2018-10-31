#include <iostream>

#include "RedBlackBinarySearchTree.h"

int main()
{
	Element* a = new Element(0);
	Element* b = new Element(1);
	Element* c = new Element(2);
	Element* d = new Element(3);
	Element* e = new Element(4);
	Element* f = new Element(5);

	RB_Tree mytree;

	mytree.insert(a);
	mytree.insert(b);
	mytree.insert(c);
	mytree.insert(d);
	mytree.insert(e);
	mytree.insert(f);

	mytree.print_inorder_detail();

	std::cin.get();
}
