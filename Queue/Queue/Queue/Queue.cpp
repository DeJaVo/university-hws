#include "Queue.h"
#include <iostream>
using namespace std;

//constructor which builds an array according to size or default size
Queue::Queue(int size)
{
	if(size<=0)//in case size is not possitive
	{
		cout<<"Illegal value"<<endl;
		return;
	}
	if((Q=new Customer[size])==0)
	{
		_size=0;
		_head=_tail=_numC=0;
		cout<<"Memory allocation error."<<endl;
		return;
	}
	else
	{
		_size=size;
		_head=_tail=_numC=0;
	}
}

Queue::Queue(const Queue& src)
{
	_size=src._size;
	_head=src._head;
	_tail=src._tail;
	_numC=src._numC;
	if((Q=new Customer[src._size])==0)
	{
		_size=_head=_tail=_numC=0;
		cout<<"Memory allocation error."<<endl;
		return;
	}
	for(int i=0; i<_size;i++)
	{
		Q[i]=src.Q[i];
	}
	return;
}
 Queue& Queue::operator=(const Queue& orig)
 {
	 if(this==&orig)
		 return *this;
	 else
	 {
		 _size=orig._size;
		_head=orig._head;
		_tail=orig._tail;
		_numC=orig._numC;
		delete[] Q;
		if((Q=new Customer[orig._size])==0)
		{
			_size=_head=_tail=_numC=0;
			cout<<"Memory allocation error."<<endl;
			return *this;
		}
		for(int i=0; i<_size;i++)
		{
			Q[i]=orig.Q[i];
		}
		return *this;
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
	return(_numC==0);
}

//adds a new customer into the queue
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
	_numC++;
	return true;
}

//removes the first in line element from queue
Customer Queue::dequeue()
{
	if(isEmpty())//if empty , returns NULL
		return NULL; 
	else
	{
		Customer x=Q[_head];
		if(_head==_size) 
			_head=0;
		else _head++;
		_numC--;
		return x;
	}
}

//prints queue
void Queue::print()
{
	int i,j=0;
	if(isEmpty())
		cout<<"queue is empty!"<<endl;
	else
	{
		for(i=_head;j<_numC;i++,j++)
		{
			cout<<(Q[(i%_size)]).getId()<<" ";
		}
		cout<<endl;
	}
}

