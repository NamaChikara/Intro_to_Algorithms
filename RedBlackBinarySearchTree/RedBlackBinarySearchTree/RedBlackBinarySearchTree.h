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
	Element* nil;		// nil sentinal for border cases
	void left_rotate(Element* x);	// assumes x's right child, y, is not nil;  y becomes the new
									//  root of the subtree, with x as y's left child and y's
									//  left child as x's right child
	void right_rotate(Element* x);	// assumes x's left child, y, is not nil and proceeds symmetrically
									//  to left_rotate
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

