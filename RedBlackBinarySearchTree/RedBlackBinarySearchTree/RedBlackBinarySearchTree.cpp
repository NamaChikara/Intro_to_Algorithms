#include "RedBlackBinarySearchTree.h"

Element::Element(int key, int color, Element* par,
	Element* left, Element* right)
	: key{ key }, color{ color }, parent{ par }, 
	left{ left }, right{ right } {}

RB_Tree::RB_Tree()
{
	nil = new Element(0, 1);
}

RB_Tree::RB_Tree(Element* first)
	: root{ first }
{
	nil = new Element(0, 1);
}

void RB_Tree::print_inorder(Element* x)
{
	if (x != nullptr)
	{
		print_inorder(x->left);
		std::cout << x->key << ", ";
		print_inorder(x->right);
	}
}

void RB_Tree::print_inorder()
{
	print_inorder(root);
}

Element* RB_Tree::search(int k)
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

Element* RB_Tree::minimum(Element* x)
{
	while (x->left != nullptr)
	{
		x = x->left;
	}
	return x;
}

Element* RB_Tree::minimum()
{
	return minimum(root);
}

Element* RB_Tree::maximum(Element* x)
{
	while (x->right != nullptr)
	{
		x = x->right;
	}
	return x;
}

Element* RB_Tree::maximum()
{
	return maximum(root);
}

Element* RB_Tree::successor(Element* x)
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

void RB_Tree::left_rotate(Element* x)
{
	Element* y = x->right;
	x->right = y->left;		
	if (y->left != nil)		// otherwise, no need to update the sentinel
	{
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nil)	// if x was the root, y is now the root
	{
		root = y;
	}
	// make y the appropriate child to be the root of the subtree
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void RB_Tree::right_rotate(Element* x)
{
	Element* y = x->left;
	x->left = y->right;
	if (y->right != nil)	// otherwise, no need to update the sentinel
	{
		y->right->parent = x;
	}
	if (x->parent = nil)	// if x was the root, y is now the root
	{
		root = y;
	}
	// make y the appropriate child to be the root of the subtree
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	y->right = x;
	x->parent = y;
}

