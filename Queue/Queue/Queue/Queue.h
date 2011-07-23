#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Customer.h"

class Queue
{
private:
	int _size;
	int _head;
	int _tail;
	int _numC;
	Customer* Q;
public:
	Queue(int size=10);
	~Queue();
	Queue(const Queue& src);
	Queue& operator=(const Queue& orig);
	bool enqueue(Customer c);
	Customer dequeue();
	bool isEmpty();
	void print();
};


#endif