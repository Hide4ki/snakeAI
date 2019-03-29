#pragma once
#include "point.h"
#include "sensor.h"
#include "enum.h"
class field;

class snake
{
	sensor **food;
	sensor **block;
	point **body;
	bool control;
	size_t size;
	direct nowDirect;
	void calculDirect(void);
	void deActivationSensor(void);
public:
	snake(size_t s, point *st, bool c);
	~snake(void);
	void activationSensor(point **overview);
	void buttonListen(void);
	void move(point *nextTurn);
	bool AIControl(void);
	friend field;	
};

