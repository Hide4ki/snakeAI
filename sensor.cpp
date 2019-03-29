#include "sensor.h"


sensor::sensor(void):state(false),top(0),left(0),right(0)
{
}

sensor::~sensor(void)
{
}

void sensor::changeState(void)
{
	state = !state;
}

bool sensor::operator()(void)const
{
	return state;
}

void sensor::send(int &t, int &l, int &r)const
{
	t += top;
	l += left;
 	r += right; 
}

ostream &operator << (ostream &stream, sensor &mySensor)
{
	stream << mySensor.left << ' ';
	stream << mySensor.right << ' ';
	stream << mySensor.top << ' ';
	return stream;
}

istream &operator >> (istream &stream, sensor &mySensor)
{
	stream >> mySensor.left;
	stream >> mySensor.right;
	stream >> mySensor.top;
	return stream;
}