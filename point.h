#pragma once

#include <iostream>
using namespace std;
#include "enum.h"
class point
{
	item value;
public:
	point(void);
	point(item a);
	~point(void);
	bool operator == (item a);
	void operator = (point &myPoint);
	void operator = (item a);
	item getItem(void)const;
	void setItem(item a);
	friend ostream &operator << (ostream &stream, point &myPoint);
};

