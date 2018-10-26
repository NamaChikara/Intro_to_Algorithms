// Implements binary tree where Elements contain an int value,
//  and pointers to their parent, left child, and right sibling

#include <iostream>
#include <sstream>
#include <string>

struct Element
{
	Element(int, Element*, Element*, Element*);
	int val;
	Element* left_child;
	Element* right_sib;
	Element* par;
	void add_child(Element*);
	void print_element();
};

Element::Element(int vv = 0, Element* left_c = nullptr,
	Element* right_s = nullptr, Element* pp = nullptr)
	: val{ vv }, left_child{ left_c }, right_sib{ right_s }, 
	par{ pp } {}

void Element::add_child(Element* child)
{
	child->par = this;
	if (left_child)	// if a child already exists
	{
		child->right_sib = left_child;
	}
	left_child = child;
}

std::string point_str(Element* e)
{
	const void *address = static_cast<const void*>(e);
	std::stringstream ss;
	ss << address;
	return ss.str();
}

void Element::print_element()
{
	if (this->par)
	{
		 std::cout << "Parent: " + point_str(par) + ", ";
	}
	else
	{
		std::cout << "No parent, ";
	}
	if (this->left_child)
	{
		std::cout << "Left-child: " + point_str(left_child) + ", ";
	}
	else
	{
		std::cout << "No left child, ";
	}
	if (this->right_sib)
	{
		std::cout << "Right sibling: " + point_str(right_sib) + ", ";
	}
	else
	{
		std::cout << "No right sib, ";
	}
	std::cout << "Value: " << val << "." << std::endl;
}

struct Tree
{
	Tree(Element*);
	Element* root;
	void print_tree();	// print tree from the bottom up
};

Tree::Tree(Element* rr = nullptr)
	: root{ rr } {}

void check_left(Element* e);

void Tree::print_tree()
{
	check_left(root);
}

void check_right(Element* e)
{
	if (e->right_sib)
	{
		check_left(e->right_sib);
	}
	else
	{
		if (e->par)
		{
			e->par->print_element();
			check_right(e->par);
		}
	}
}

void check_left(Element* e)
{
	if (e->left_child)
	{
		check_left(e->left_child);
	}
	else
	{
		e->print_element();
		check_right(e);
	}
}

int main()
{
	Element* e1 = new Element{ 0 };
	Tree mytree{ e1 };
	Element* e2 = new Element{ 1 };
	e1->add_child(e2);
	Element* e3 = new Element{ 2 };
	e1->add_child(e3);
	Element* e4 = new Element{ 3 };
	e3->add_child(e4);
	mytree.print_tree();
	std::cin.get();
}