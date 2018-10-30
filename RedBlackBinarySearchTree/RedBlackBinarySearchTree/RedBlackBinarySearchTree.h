#pragma once

#ifndef REDBLACKBINARYSEARCHTREE_H
#define REDBLACKBINARYSEARCHTREE_H

#include <iostream>

struct Element
{
	Element(int, int, Element* = nullptr,
		Element* = nullptr, Element* = nullptr);
	int key;
	int color;			// 0 == red, 1 == black
	Element* parent;
	Element* left;
	Element* right;
};

class RB_Tree
{
public:
	RB_Tree();
	RB_Tree(Element*);	// set root to be equal to the argument
private:
	Element* root;
	void transplant(Element* u, Element* v);	// replace subtree u as a child of its parent with subtree v
public:
	void print_inorder(Element*);	// if printing the subtree with argument as its base
	void print_inorder();			// if printing the whole tree
	Element* search(int);		// return pointer to Element holding the argument as its key
	Element* minimum(Element*);	// if searching a subtree (i.e. starting at a specific Element)
	Element* minimum();			// if searching the whole tree (i.e. starting at root)
	Element* maximum(Element*);
	Element* maximum();
	Element* successor(Element*);	// return the immediate successor of the argument
};

#endif // 

