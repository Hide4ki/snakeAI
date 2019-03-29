#include "snake.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

snake::snake(size_t s, point *st, bool c):size(s),control(c)
{
	food = new sensor*[N];
	block = new sensor*[N];
	ifstream fin("AI.txt");
	nowDirect = TOP;
	if(!fin)
		throw "file AI, don't open";
	for(int i = 0; i < N; i++)
	{
		food[i] = new sensor[N];
		for(int j = 0; j < N; j++)
			fin >> food[i][j];
	}
	for(int i = 0; i < N; i++)
	{
		block[i] = new sensor[N];
		for(int j = 0; j < N; j++)
			fin >> block[i][j];
	}
	body = new point*[X*X];
	body[0] = st;
}

snake::~snake(void)
{
	delete[] body;
	for(int i = 0; i<N; i++)
	{
		delete[] food[i];
		delete[] block[i];
	}
	delete[] food;
	delete[] block;
}

void snake::calculDirect(void)
{
	int top = 10;
	int left = 5;
	int right = 0;
	for(int i = 0; i<N; i++)
		for(int j = 0; j<M; j++)
		{
			if(food[i][j]())
				food[i][j].send(top, left, right);
			if(block[i][j]())
				block[i][j].send(top, left, right);
		}
	direct relativDirect = (top>=left)?(top>=right)?TOP:RIGHT:(left>=right)?LEFT:RIGHT;
  	nowDirect = (direct)((nowDirect+relativDirect)%4);
}

bool snake::AIControl(void)
{
	return control;
}

void snake::activationSensor(point **overview)
{
	deActivationSensor();	
	for(int i = 0; i<M; i++)
		for(int j = 0; j<N; j++)
		{
			if(overview[i][j] == WALL || overview[i][j] == SNAKE)
				block[i][j].changeState();
			if(overview[i][j] == EAT)
				food[i][j].changeState();
		}
}

void snake::deActivationSensor(void)
{
	for(int i = 0; i<M; i++)
		for(int j = 0; j<N; j++)
		{
			if(block[i][j]())
				block[i][j].changeState();
			if(food[i][j]())
				food[i][j].changeState();
		}
}

void snake::buttonListen(void)
{
	char button;
	switch(button = _getch())
	{
	case 'w':
		nowDirect = (nowDirect!=BOTTOM)?TOP:nowDirect;
		break;
	case 's':
		nowDirect = (nowDirect!=TOP)?BOTTOM:nowDirect;
		break;
	case 'a':
		nowDirect = (nowDirect!=RIGHT)?LEFT:nowDirect;
		break;
	case 'd':
		nowDirect = (nowDirect!=LEFT)?RIGHT:nowDirect;
		break;
	case 'q':
		throw "GameOver";
	}
}

void snake::move(point *nextTurn)
{
	if(*nextTurn==WALL || *nextTurn==SNAKE)
		throw "GameOver";
	if(*nextTurn==EAT)
		size++;
	else
		*body[size-1] = (VOID);
	*nextTurn = SNAKE;
	for(int i = size-1; i>0; i--)
		body[i] = body[i-1];
	body[0] = nextTurn;
}
