#pragma once
#include "snake.h"

class player
{
	snake *base;
	int head_x;
	int head_y;
public:
	player(void);
	~player(void);
};

