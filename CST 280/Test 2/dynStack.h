// Specification file for the DynStack class
// which stores a stack implemented as a linked
// structure and utilizing templates
#ifndef DYNSTACK_H
#define DYNSTACK_H

template <class ItemType>
class DynStack
{
private:
	struct NodeType
	{
		ItemType info;
		NodeType *next;
	};

	NodeType *top;

public:
	DynStack();
	~DynStack();
	void push(ItemType);
	ItemType pop();
	bool isEmpty();
	bool isFull();
	void clear();
};

#endif

//==================================================
//Implementation for Dynamic Stack class
//==================================================

#include <iostream>
using namespace std;

//**************************************************
// Constructor                                     *
// This function deletes every node in the list.   *
//**************************************************

template <class ItemType>
DynStack<ItemType>::DynStack()
{
	top = NULL;
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

template <class ItemType>
DynStack<ItemType>::~DynStack()
{
	clear();
}

//************************************************
// Member function push pushes the argument onto *
// the stack.                                    *
//************************************************

template <class ItemType>
void DynStack<ItemType>::push(ItemType item)
{
	NodeType *newNode;

	// Allocate a new node & store Num
	newNode = new NodeType;
	newNode->info = item;

	// If there are no nodes in the list
	// make newNode the first node and its next NULL
	newNode->next = top;
	top = newNode;
}

//****************************************************
// Member function pop pops the value at the top     *
// of the stack off, and copies it into the variable *
// passed as an argument.                            *
// PRECONDITION:  Stack is not empty                 *
//****************************************************

template <class ItemType>
ItemType DynStack<ItemType>::pop()
{
	NodeType *temp;
	ItemType item;

	// pop value off top of stack
	item = top->info;
	temp = top;
	top = top->next;
	delete temp;
	return item;
}

//****************************************************
// Member function isEmpty returns true if the stack *
// is empty, or false otherwise.                     *
//****************************************************

template <class ItemType>
bool DynStack<ItemType>::isEmpty()
{
	bool status;

	if (top == NULL)
		status = true;
	else
		status = false;

	return status;
}

//****************************************************
// Member function isFull is assumed to be false.    *
// Tailor to local operating environment.            *
//****************************************************

template <class ItemType>
bool DynStack<ItemType>::isFull()
{
	return false;
}

//********************************************
// Function clear pops all the elements      *
// off of the stack to empty it.             *
//********************************************

template <class ItemType>
void DynStack<ItemType>::clear()
{
	NodeType *nodePtr, *nextNode;

	nodePtr = top;
	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	top = NULL;
}



