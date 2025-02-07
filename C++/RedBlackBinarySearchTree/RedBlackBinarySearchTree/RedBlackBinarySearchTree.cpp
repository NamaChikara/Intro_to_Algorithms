#include "RedBlackBinarySearchTree.h"

Element::Element(int key, int color, Element* par,
	Element* left, Element* right)
	: key{ key }, color{ color }, parent{ par }, 
	left{ left }, right{ right } {}

std::string Element::point_str()
{
	const void *address = static_cast<const void*>(this);
	std::stringstream ss;
	ss << address;
	return ss.str();
}

void Element::print_element()
{
	std::string e_col = (color == 0) ? "red" : "black";
	std::cout << "-------------\n";
	std::cout << "key value: " << key << ", color: " << e_col << std::endl;
	std::cout << std::setw(20) << "this location: " << point_str() << std::endl;
	std::cout << std::setw(20) << "this parent: " << parent->point_str() << std::endl;
	std::cout << std::setw(20) << "this left child: " << left->point_str() << std::endl;
	std::cout << std::setw(20) << "this right child: " << right->point_str() << std::endl;
	std::cout << "-------------\n";
}

RB_Tree::RB_Tree()
{
	nil = new Element(0, 1);
	root = nil;
}

RB_Tree::RB_Tree(Element* first)
	: root{ first }
{
	nil = new Element(0, 1);
}

void RB_Tree::print_inorder(Element* x)
{
	if (x != nil)
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

void RB_Tree::print_inorder_detail(Element* x)
{
	if (x != nil)
	{
		print_inorder_detail(x->left);
		x->print_element();
		print_inorder_detail(x->right);
	}
}

void RB_Tree::print_inorder_detail()
{
	print_inorder_detail(root);
}

Element* RB_Tree::search(int k)
{
	Element* x = root;
	while (x != nil && k != x->key)
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
	while (x->left != nil)
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
	while (x->right != nil)
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
	if (x->right != nil)
	{
		return minimum(x->right);
	}
	Element* y = x->parent;
	while (y != nil && x == y->right)
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

void RB_Tree::insert_fixup(Element* z)
{
	while (z->parent->color == 0)
	{	
		// locate z's "uncle"
		if (z->parent == z->parent->parent->left)
		{
			Element* y = z->parent->parent->right;
			if (y->color == 0)
			// make z's parent and uncle black, grandparent red, and advance up tree
			{
				z->parent->color = 1;
				y->color = 1;
				z->parent->parent->color = 0;
				z = z->parent->parent;
			}
			else	// we can rotate and recolor to satisfy RB properties
			{
				if (z == z->parent->right)
				// rotate so that we can recolor correctly
				{
					z = z->parent;
					left_rotate(z);
				}
				z->parent->color = 1;	// hence the while loop will finish executing
				z->parent->parent->color = 0;
				right_rotate(z->parent->parent);
			}
		}
		else
		{
			Element* y = z->parent->parent->left;
			if (y->color == 0)
				// make z's parent and uncle black, grandparent red, and advance up tree
			{
				z->parent->color = 1;
				y->color = 1;
				z->parent->parent->color = 0;
				z = z->parent->parent;
			}
			else	// we can rotate and recolor to satisfy RB properties
			{
				if (z == z->parent->left)
					// rotate so that we can recolor correctly
				{
					z = z->parent;
					right_rotate(z);
				}
				z->parent->color = 1;	// hence the while loop will finish executing
				z->parent->parent->color = 0;
				left_rotate(z->parent->parent);
			}
		}
	}
	root->color = 1;	// if (z->parent->color == 0) takes us up the tree until
						//  z->parent->parent == root, then the root's color is set 
						//  to red and since the root's parent is the (black) sentinel,
						//  we will exit the while loop with a red root (contradicting a RB property)
}

void RB_Tree::insert(Element* z)
{
	Element* y = nil;
	Element* x = root;
	while (x != nil)	// travel down the tree based on key comparisons
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
	// make z a new leaf of the RB_Tree (or the root if y = nil)
	z->parent = y;
	if (y == nil)
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
	z->left = nil;
	z->right = nil;
	z->color = 0;
	// now make sure the color properties are maintained
	insert_fixup(z);
}

void RB_Tree::transplant(Element* u, Element* v)
{
	if (u->parent == nil)
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
	v->parent = u->parent;
}

void RB_Tree::delete_fixup(Element* x)
{
	// within the while loop, x always points to a nonroot doubly black node
	//  the goal of the while loop is to move the extra black up the tree until
	//  termination: (1) x points to a red-and-black node; it is then colored (singly) black
	//			     (2) x points to the root; make x singly black 
	// w is maintained to be the sibling of x
	while (x != root && x->color == 1)
	{
		if (x == x->parent->left)
		{
			Element* w = x->parent->right;
			if (w->color == 0)
			// case 1: x's sibling w is red. take action to fall through to case 2,3, or 4
			{
				// Since w must have black children, switching the colors of w and x->parent
				//  and left-rotating on x->parent does not violate color properties
				w->color = 1;
				x->parent->color = 0;
				left_rotate(x->parent);	// Note that w->left (black) has become x's sibling; 
										//  case 1 falls through to 2, 3, or 4
				w = x->parent->right;	// maintain that w is x's sibling
			}
			if (w->left->color == 1 && w->right->color == 1)
			// case 2: x's sibling w and its children are all black.  take 
			{	
				// take one black off both x and w, treat x->parent as doubly black
				w->color = 0;
				x = x->parent;	// if fell through from case 1, x->parent is now red-black so the 
								//  while loop will terminate in order to color x->parent singly black
			}
			else
			{
				if (w->right->color == 1)
					// case 3: x's sibling w is black, w's left child is red, and w's right child is black
				{
					// Switch w and w->left's colors then right rotate on w without any color violations.
					w->left->color = 1;
					w->color = 0;
					right_rotate(w);
					w = x->parent->right;	// x's sibling is now a black node with a red right child (case 4)
				}
				// case 4: x's sibling w is black, and w's right child is red
				//  make color changes and left rotate x->parent to make x singly black
				w->color = x->parent->color;
				x->parent->color = 1;
				w->right->color = 1;
				left_rotate(x->parent);
				// set x to point to the root so that the while loop will terminate
				x = root;	
			}	
		}
		// symmetric to the clause executed when x == x->parent->left
		else
		{
			Element* w = x->parent->left;
			if (w->color == 0)
			{
				w->color = 1;
				x->parent->color = 0;
				right_rotate(x->parent);			
				w = x->parent->left;	
			}
			if (w->left->color == 1 && w->right->color == 1) 
			{
				w->color = 0;
				x = x->parent;
			}
			else
			{
				if (w->left->color == 1)
				{
					w->right->color = 1;
					w->color = 0;
					left_rotate(w);
					w = x->parent->left;	
				}
				w->color = x->parent->color;
				x->parent->color = 1;
				w->left->color = 1;
				right_rotate(x->parent);
				x = root;
			}
		}
	}
	x->color = 1;
}

void RB_Tree::remove(Element* z)
{
	// maintain y as the removed node or node moved within the tree
	// maintain x as the node that moves into y's original position	

	Element* y = z;	
	int y_original_color = y->color;
	Element* x = nil;

	// case 1: no left child; simply replace z by its right child
	if (z->left == nil)
	{
		Element* x = z->right;	
		transplant(z, z->right);
	}
	// case 2: only one child, which is left child; replace z by its left child
	else if (z->right == nil)
	{
		Element* x = z->left;
		transplant(z, z->left);
	}
	// case 3: right and left child
	else
	{
		// first, locate z's successor 
		y = minimum(z->right);
		y_original_color = y->color;
		x = y->right;	// if a node in a binary search tree has two children, then its
								//  successor has no left child; 
		if (y->parent == z)
		{
			x->parent = y;
		}
		// if y is not z's right child, replace y by its own right child
		else
		{
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		// replace z by y
		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	// if a black node was moved, red-black color properties may be violated
	if (y_original_color == 1)
	{
		std::cout << "x's key: " << x->key << std::endl;
		delete_fixup(x);
	}
}