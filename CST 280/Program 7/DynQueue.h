#ifndef DYNQUEUE_H 
#define DYNQUEUE_H 

template <class ItemType>
class DynQueue
{
private:
	struct NodeType
	{
		ItemType info;
		NodeType *next;
	};

	NodeType *front;
	NodeType *rear;
	int numItems;
public:
	DynQueue();
	~DynQueue();
	void enqueue(ItemType);
	ItemType dequeue();
	bool isEmpty();
	bool isFull();
	void clear();
};

#endif 

//================================================== 
//Implementation for Dynamic Queue class 
//================================================== 

#include <iostream> 
using namespace std;

//************************ 
// Constructor           * 
//************************ 

template <class ItemType>
DynQueue<ItemType>::DynQueue()
{
	front = NULL;
	rear = NULL;
	numItems = 0;
}

//************************ 
// Destructor            * 
//************************ 

template <class ItemType>
DynQueue<ItemType>::~DynQueue()
{
	clear();
}

//******************************************** 
// Function enqueue inserts the value in num * 
// at the rear of the queue.                 * 
//******************************************** 

template <class ItemType>
void DynQueue<ItemType>::enqueue(ItemType item)
{
	NodeType *newNode;

	newNode = new NodeType;
	newNode->info = item;
	newNode->next = NULL;
	if (isEmpty())
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
	numItems++;
}

//********************************************** 
// Function dequeue removes the value at the   * 
// front of the queue, and copies it into num. * 
// PRECONDITION:  Queue is not empty           * 
//********************************************** 

template <class ItemType>
ItemType DynQueue<ItemType>::dequeue()
{
	NodeType *temp;
	ItemType returnItem;

	returnItem = front->info;
	temp = front;
	front = front->next;
	delete temp;
	numItems--;
	return returnItem;
}

//********************************************* 
// Function isEmpty returns true if the queue * 
// is empty, and false otherwise.             * 
//********************************************* 

template <class ItemType>
bool DynQueue<ItemType>::isEmpty()
{
	bool status;

	if (numItems > 0)
		status = false;
	else
		status = true;
	return status;
}

//**************************************************** 
// Member function isFull is assumed to be false.    * 
// Tailor to local operating environment.            * 
//**************************************************** 

template <class ItemType>
bool DynQueue<ItemType>::isFull()
{
	return false;
}

//******************************************** 
// Function clear dequeues all the elements  * 
// in the queue.                             * 
//******************************************** 

template <class ItemType>
void DynQueue<ItemType>::clear()
{
	ItemType value;   // Dummy variable for dequeue 

	while (!isEmpty())
		value = dequeue();
}


