#pragma once
#include <iostream>
using namespace std;
#include "enum.h"

class sensor
{
	bool state;
	int top;
	int left;
	int right;
public:
	sensor(void);
	~sensor(void);
	void changeState(void);
	bool operator()(void)const;
	void send(int &t, int &l, int &r)const;
	friend ostream &operator << (ostream &stream, sensor &mySensor);
	friend istream &operator >> (istream &stream, sensor &mySensor);
};

