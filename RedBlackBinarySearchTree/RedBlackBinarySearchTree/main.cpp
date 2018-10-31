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

	std::cout << "Create empty Red-Black binary search tree and "
		<< "insert nodes with keys 0, 1, 2, 3, 4, 5 (in order).\n\n";

	RB_Tree mytree;

	mytree.insert(a);
	mytree.insert(b);
	mytree.insert(c);
	mytree.insert(d);
	mytree.insert(e);
	mytree.insert(f);

	mytree.print_inorder_detail();

	mytree.remove(d);

	std::cout << "\n Remove node with key 3.\n\n";

	mytree.print_inorder_detail();

	std::cin.get();
}
