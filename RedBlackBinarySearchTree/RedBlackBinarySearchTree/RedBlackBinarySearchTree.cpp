#include "RedBlackBinarySearchTree.h"

Element::Element(int key, int color, Element* par,
	Element* left, Element* right)
	: key{ key }, color{ color }, parent{ par }, 
	left{ left }, right{ right } {}

RB_Tree::RB_Tree() {}

RB_Tree::RB_Tree(Element* first)
	: root{ first } {}

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