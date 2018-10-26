// Implements a linked list and que; provides pop and push operations for a 
//  stack built through a linked list.

#include<iostream>

struct Item {
	Item(int vv = 0, Item* pp = nullptr, Item* nn = nullptr)
		: val{ vv }, prev{ pp }, next{ nn } {}
	int val;
	Item* prev;
	Item* next;
};

struct List {
	List(Item* first)
	{
		nil = Item(0, first, first);
		first->prev = &nil;
		first->next = &nil;
	}
	Item nil;
};

void print_item(Item* i)
{
	std::cout << '(' << i->prev->val << ','
		<< i->val << ',' << i->next->val << ')';
}

void print_list(const List &l)
{
	Item* i = l.nil.next;
	while (i != &l.nil)
	{
		print_item(i);
		std::cout << ',';
		i = i->next;
	}
	std::cout << std::endl;
}

// Insert an item to the front of a linked list
void insert(List &l, Item *e)
{
	e->next = l.nil.next;
	l.nil.next->prev = e;
	l.nil.next = e;
	e->prev = &l.nil;
}

// Delete an item from a linked list
void list_delete(Item* e)
{
	e->prev->next = e->next;
	e->next->prev = e->prev;
}

// ---------------------
// Que implementation
// ---------------------

struct Que {
	Que()
	{
		head = tail = nullptr;
	}
	Item* head;
	Item* tail;

	void insert(int);
	void delete_item();
	void print();

	~Que();
};

void Que::insert(int x)
{
	Item* temp = new Item;
	temp->val = x;
	temp->next = nullptr;
	// in case of first Item
	if (head == nullptr)
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}

void Que::delete_item()
{
	if (head == nullptr)
	{
		std::cout << "Underflow" << std::endl;
		return;
	}
	std::cout << head->val << 'd' << std::endl;
	if (head == tail)	// in case there is only one node
	{
		head = tail = nullptr;
	}
	else
	{
		head = head->next;
	}
}

void Que::print()
{
	if (head == nullptr)
	{
		std::cout << "Underflow" << std::endl;
		return;
	}
	Item *place = head;
	while (place)
	{
		std::cout << place->val << ',';
		place = place->next;
	}
	std::cout << std::endl;
}

Que::~Que()
{
	while (head != nullptr)
	{
		Item *temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
}

// Push operation for a stack using a linked list
void push(List &l, int x)
{
	Item* i = new Item(x, l.nil.prev, &l.nil);
	l.nil.prev->next = i;
	l.nil.prev = i;
}

// Pop operation for a stack using a linked list
int pop(List &l)
{
	if (l.nil.next != l.nil.prev)
	{
		int x = l.nil.prev->val;
		l.nil.prev->prev->next = &l.nil;
		l.nil.prev = l.nil.prev->prev;
		return x;
	}
	return 0;
}

int main()
{
	Item* i1 = new Item(1);
	List myList{ i1 };
	Item* i2 = new Item(2);
	insert(myList, i2);
	push(myList, 3);
	print_list(myList);
	std::cout << pop(myList) << std::endl;
	print_list(myList);
	Que myQue;
	myQue.insert(1);
	myQue.insert(2);
	myQue.print();
	myQue.delete_item();
	myQue.print();
	myQue.~Que();
	myQue.print();
	std::cin.get();
}