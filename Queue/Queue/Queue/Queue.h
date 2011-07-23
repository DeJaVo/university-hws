#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "Customer.h"

class Queue
{
private:
	int _size;
	int _head;
	int _tail;
	Customer* Q;
	bool _isArray;
	bool _isList;
public:
	Queue();
	Queue(int size);
	~Queue();
	Queue(const Queue&);
	Queue& operator=(const Queue& orig);
	bool enqueue(Customer c);
	Customer dequeue();
	Customer top();
	bool isEmpty();
	void print();
};


#endif