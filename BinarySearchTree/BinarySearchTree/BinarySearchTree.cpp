#include "BinarySearchTree.h"

Element::Element(int key, Element* par,
	Element* left, Element* right)
	: key{ key }, parent{ par }, left{ left }, right{ right } {}

Tree::Tree() {}

Tree::Tree(Element* first)
	: root{ first } {}

Element* Tree::search(int k)
{
	Element* x = root;
	while (x != nullptr && k != x->key)
	{
		if (k < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	return x;
}

Element* Tree::minimum()
{
	return minimum(root);
}

Element* Tree::minimum(Element* x)
{
	while (x->left != nullptr)
	{
		x = x->left;
	}
	return x;
}

Element* Tree::maximum()
{
	return maximum(root);
}

Element* Tree::maximum(Element* x)
{
	while (x->right != nullptr)
	{
		x = x->right;
	}
	return x;
}

Element* Tree::successor(Element* x)
{
	if (x->right != nullptr)
	{
		return minimum(x->right);
	}
	Element* y = x->parent;
	while (y != nullptr && x == y->right)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

void Tree::insert(Element* z)
{
	Element* y = nullptr;
	Element* x = root;
	while (x)
	{
		y = x;
		if (z->key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	z->parent = y;
	if (y == nullptr)
	{
		root = z;
	}
	else if (z->key < y->key)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}
}