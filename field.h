#pragma once
#include "point.h"
#include "enum.h"

#include "snake.h"

class field
{
	snake *players;
	point **body;
	int head_x;
	int head_y;
public:
	field(void);
	~field(void);
	void createEat(void);
	bool checkEat(int x, int y);
	bool checkBorder(int Row, int Col);
	friend ostream &operator << (ostream &stream, field &myField); 
	void nextRound(void);
};

