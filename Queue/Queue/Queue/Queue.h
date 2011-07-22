#ifndef _QUEUE_H_
#define _QUEUE_H_

class Queue
{
private:
	int _size;
	int _head;
	int _tail;
	int* Q;
public:
	Queue(int size);
	~Queue();
	Queue(const Queue&);
	Queue& operator=(const Queue& orig);
	bool enqueue( int el);
	int dequeue();
	int top();
	bool isEmpty();
	

};


#endif