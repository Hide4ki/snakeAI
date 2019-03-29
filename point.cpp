#include "point.h"

point::point(void):value(VOID)
{
}

point::point(item a):value(a)
{
}

point::~point(void)
{
}

item point::getItem(void)const
{
	return value;
}

void point::setItem(item a)
{
	value = a;
}

bool point::operator == (item a)
{
	return value==a;
}

ostream &operator << (ostream &stream, point &myPoint)
{
	stream << myPoint.value << ' ';
	return stream;
}

void point::operator = (point &myPoint)
{
	value = myPoint.value;
}
 
void point::operator = (item a)
{
	value = a;
}
