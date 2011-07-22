#include <iostream>
#include "Queue.h"
#include "Customer.h"

using namespace std;

int main() {
	Queue q1;
	Queue q2(3);
	Queue q3(5);

	for (int i = 0; i < 13; i++)
	{
		Customer c(i);
		bool in = q1.enqueue(c);
		if (i <= 9 && !in)
		{
			cout << "ERROR: default size is smaller than 10!!" << endl;
		}
		else if (i > 9 && in)
		{
			cout << "ERROR: default size is bigger than 10!!" << endl;
		}
	}
	q1.print();
	cout << "0 1 2 3 4 5 6 7 8 9 ***********" << endl;

	for (int i = 0; i < 10; i++)
	{
		Customer el = q1.dequeue();
		if (i != el.getId()){
			cout << "Error: dequeue order is not correct!!";
		}
	}
	cout << endl;

	Customer underflow = q1.dequeue();
	if (underflow.getId() != 0)
	{
		cout << "ERROR: underflow not taken care of!!" << endl;
	}

	Customer c1(12, "moni");
	if (!q3.enqueue(c1))
	{
		cout << "ERROR: cannot add element to queue 3!!" << endl;
	}
	Customer c2(14, "mobi");
	if (!q3.enqueue(c2)){
		cout << "ERROR: cannot add element to queue 3!!" << endl;
	}

	Queue q4(q3);

	if (q3.dequeue().getId() != 12)
	{
		cout << "ERROR: cdequeue should return the first element in line (12)!!" << endl;
	}

	if (!q4.enqueue(21)){
		cout << "ERROR: cannot add element to queue 4!!" << endl;
	}

	if (!q4.enqueue(7)){
		cout << "ERROR: cannot add element to queue 4!!" << endl;
	}

	if (!q4.enqueue(332)){
		cout << "ERROR: cannot add element to queue 4!!" << endl;
	}

	if (q4.enqueue(12)){
		cout << "ERROR: add element number 6 to queue with size 5 (q4)!!" << endl;
	}
          
	q4.print();
	cout << "12 14 21 7 332 ***********" << endl;
	q3.print();
	cout << "14 ***********" << endl;

	q2.print();
	cout << "queue is empty! ***********" << endl;

	q2 = q3;
	q2.print();
	cout << "14 ***********" << endl;

	if (!q2.enqueue(17)){
		cout << "ERROR: cannot add element to queue 2!!" << endl;
	}

	if (!q2.enqueue(18)){
		cout << "ERROR: cannot add element to queue 2!!" << endl;
	}

	if (!q2.enqueue(3521)){
		cout << "ERROR: cannot add element to queue 2!!" << endl;
	}

	q2.print();
	cout << "14 17 18 3521 ***********" << endl;
	q3.print();
	cout << "14 ***********" << endl;

	return 0;
}