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
	Tree(Element*);
//private:
	Element* root;
public:
	Element* search(int);

	// if searching the whole tree (i.e. starting at root)
	Element* minimum();	
	Element* maximum();
	// if searching a subtree (i.e. starting at a specific Element)
	Element* minimum(Element*);
	Element* maximum(Element*);

	Element* successor(Element*);
	void insert(Element*);
};



#endif // 

