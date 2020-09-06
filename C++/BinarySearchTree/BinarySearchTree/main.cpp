#include <iostream>

#include "BinarySearchTree.h"

int main()
{
	std::cout << "Total list of keys: 2, 8, 10, 11, 15, 33, 100.\n\n";
	Element* a = new Element(10);
	Element* b = new Element(8);
	Element* c = new Element(2);
	Element* d = new Element(11);
	Element* e = new Element(33);
	Element* f = new Element(15);
	Element* g = new Element(100);

	std::cout << "Creating tree with root key 15.\n";

	Tree mytree{ f };

	mytree.insert(a);
	mytree.insert(b);
	mytree.insert(c);
	mytree.insert(d);
	mytree.insert(e);
	mytree.insert(g);

	std::cout << "Printing tree in order via Tree::print_inorder().\n";
	mytree.print_inorder();
	std::cout << std::endl << std::endl;

	std::cout << "Printing tree in order starting at Element with key "
		" 11 via Tree::print_inorder(Element*).\n";
	mytree.print_inorder(d);
	std::cout << std::endl << std::endl;

	std::cout << "Minimum calculated by Tree::minimum(): " << mytree.minimum()->key
		<< ".\nMaximum calculated by Tree::maximum(): " << mytree.maximum()->key
		<< ".\n\n.";

	std::cout << "Successor of Element with key 8 determined by Tree::successor(Element*): "
		<< mytree.successor(b)->key << ".\n\n";

	Element* h = new Element(40);
	mytree.insert(h);
	std::cout << "Tree::print_inorder() after new element with key value 40 "
		<< "was inserted via Tree::insert(Element*):\n";
	mytree.print_inorder();
	std::cout << std::endl << std::endl;

	mytree.remove(a);
	std::cout << "Tree::print_inoder() after element with key 10 removed from tree "
		<< "via Tree::remove(Element*):\n";
	mytree.print_inorder();
	std::cout << std::endl;

	std::cin.get();
}