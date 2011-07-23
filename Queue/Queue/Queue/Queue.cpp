#include "Queue.h"
#include <iostream>
using namespace std;

//constructor which builds an array according to size or default size
Queue::Queue(int size=10)
{
	if((Q=new Customer[size])==0)
	{
		_size=0;
		_head=_tail=0;
		cout<<"Memory allocation error."<<endl;
		return;
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

//adds a new element into the queue
bool Queue::enqueue(Customer c)
{
	int next_tail=_tail;
	if(next_tail==_size)
		next_tail=0;
	else next_tail++;
	if(next_tail==_head)//in case queue is full
		return false;
	Q[_tail]=c;
	_tail=next_tail;
	return true;
}

//removes the first in line element from queue
Customer Queue::dequeue()
{
	if(isEmpty())//if empty , returns 0
		return 0; 
	else
	{
		Customer x=Q[_head];
		if(_head==_size) 
			_head=0;
		else _head++;
		return x;
	}
}

//p
void Queue::print()
{
	int i=0;
	if(isEmpty())
		cout<<"queue is empty!"<<endl;
	else
	{
		for(i=0;i<_size;i++)
		{
			cout<<(Q[i]).getId()<<" ";
		}
		cout<<endl;
	}
}

