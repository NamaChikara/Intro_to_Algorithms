#pragma once

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

struct Element
{
	Element(int, Element* = nullptr, 
		Element* = nullptr, Element* = nullptr);
	int key;
	Element* parent;
	Element* left;
	Element* right;
};

class Tree
{
public:
	Tree();
	Tree(Element*);	// set root to be equal to the argument
private:
	Element* root;
public:
	void print_inorder(Element*);	// if printing the subtree with argument as its base
	void print_inorder();			// if printing the whole tree
	Element* search(int);		// return pointer to Element holding the argument as its key
	Element* minimum(Element*);	// if searching a subtree (i.e. starting at a specific Element)
	Element* minimum();			// if searching the whole tree (i.e. starting at root)
	Element* maximum(Element*);
	Element* maximum();
	Element* successor(Element*);	// return the immediate successor of the argument
	void insert(Element*);			// insert Element into the tree
	void transplant(Element* u, Element* v);	// replace subtree u as a child of its parent with subtree v
	void remove(Element*);						// remove Element from the tree
};

#endif // 

