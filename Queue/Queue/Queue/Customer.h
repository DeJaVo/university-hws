#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <string>
using namespace std;

class Customer {
public:
	Customer(int id=1111, string name="lili"):_id(id),_name(name){}

	int getId() const {return _id;}
	string getName() const {return _name;}

private:
	int _id;
	string _name;
};

#endif