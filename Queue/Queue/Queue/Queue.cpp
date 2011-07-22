#include "Queue.h"
#include <iostream>
using namespace std;

//constructor
Queue::Queue(int size)
{
	if((Q=new int[size])==0)
	{
		_size=0;
		_head=_tail=0;
	}
	else
	{
		_size=size;
		_head=_tail=0;
	}
}
//destructor
Queue::~Queue()
{
	if(_size!=0)
		delete[] Q; 
}

//checks if the queue is empty
bool Queue::isEmpty()
{
	return(_head==_tail);
}

//returns the first in queue element, if Q is empty prints a message
int Queue::top()
{
	if(isEmpty())
		cout<<"Queue is empty"<<endl;
	return Q[_head];
}
//adds a new element into the queue
bool Queue::enqueue(int el)
{
	int next_tail=_tail;
	if(next_tail==_size)
		next_tail=1;
	else next_tail++;
	if(next_tail==_head)//in case queue is full
	{
		cout<<"Queue is full"<<endl;
		return false;
	}
	Q[_tail]=el;
	_tail=next_tail;
	return true;
}

//removes an element from queue
int Queue::dequeue()
{
	if(isEmpty())
	{
		cout<<"Queue is empty"<<endl;
		return 0; //remind in case of no zeros
	}
	else
	{
		int x=Q[_head];
		if(_head==_size) 
			_head=0;
		else _head++;
		return x;
	}
}

