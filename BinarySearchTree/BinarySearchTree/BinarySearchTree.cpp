#include "BinarySearchTree.h"

Element::Element(int key, Element* par,
	Element* left, Element* right)
	: key{ key }, parent{ par }, left{ left }, right{ right } {}

Tree::Tree() {}

Tree::Tree(Element* first)
	: root{ first } {}

void Tree::print_inorder(Element* x)
{
	if (x != nullptr)
	{
		print_inorder(x->left);
		std::cout << x->key << ", ";
		print_inorder(x->right);
	}
}

void Tree::print_inorder()
{
	print_inorder(root);
}

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

Element* Tree::minimum(Element* x)
{
	while (x->left != nullptr)
	{
		x = x->left;
	}
	return x;
}

Element* Tree::minimum()
{
	return minimum(root);
}

Element* Tree::maximum(Element* x)
{
	while (x->right != nullptr)
	{
		x = x->right;
	}
	return x;
}

Element* Tree::maximum()
{
	return maximum(root);
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

void Tree::transplant(Element* u, Element* v)
{
	if (u->parent == nullptr)
	{
		root = v;
	}
	else if (u == u->parent->left)
	{
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}
	if (v != nullptr)
	{
		v->parent = u->parent;
	}
}

void Tree::remove(Element* z)
{
	// case 1: no left child; simply replace z by its right child
	if (z->left == nullptr)
	{
		transplant(z, z->right);
	}
	// case 2: only one child, which is left child; replace z by its left child
	else if (z->right == nullptr)
	{
		transplant(z, z->left);
	}
	// case 3: right and left child
	else
	{
		// first, locate z's successor 
		Element* y = minimum(z->right);
		// if y is not z's right child, replace y by its own right child
		if (y->parent != z)
		{
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		// replace z by y
		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
	}
}