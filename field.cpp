#include "field.h"
void field::createEat(void)
{
	int x = (rand()%(X-1));
	int y = (rand()%(X-1));
	if(!checkEat(x,y))
		createEat();
	else
		body[x][y] = EAT;
}

bool field::checkEat(int x, int y)
{
	return body[x][y]==VOID;
}

field::field(void)
{
	body = new point*[X];
	for(int i = 0; i<X; i++)
		body[i] = new point[X];
	for(int i = 0; i<X; i++)
	{
		body[i][0] = WALL; 
		body[0][i] = WALL; 
		body[i][X-1] = WALL; 
		body[X-1][i] = WALL; 
	}
	players = new snake(1, &body[5][5], true);
	head_x = 5;
	head_y = 5;
	body[head_x][head_y] = SNAKE;
}

field::~field(void)
{
	for(int i = 0; i<X; i++)
		delete[] body[i];
	delete[] body;
	delete players;
}

void show(point **tmp)
{
	for(int i = 0; i<N; i++)
{			for(int j = 0; j<N; j++)
				cout<<tmp[i][j] << ' ';
	cout << endl;
}
}

void rotate(point **mas, direct k)
{
	show(mas);
	point tmp = VOID;
	for(int p = 0; p<(int)k;p++)
	{
	for(int i = 0; i<N/2;i++)
		for(int j = i; j<N-i-1; j++)
		{
			tmp = mas[i][j];
			mas[i][j] = mas[j][N-1-i];
			mas[j][N-1-i] = mas[N-1-i][N-1-j];
			mas[N-1-i][N-1-j] = mas[N-1-j][i];
			mas[N-1-j][i] = tmp;
		}
	}
}

void field::nextRound(void)
{
	if(players->AIControl())
	{
		point **tmp = new point*[N];
		for(int i = 0; i<N; i++)
			tmp[i] = new point[M];
		for(int i = head_x-2; i<=head_x+2; i++)
			for(int j = head_y-2; j<=head_y+2; j++)
			{
				tmp[i-(head_x-2)][j-(head_y-2)] = checkBorder(i,j)?body[i][j]:VOID;
			//	cout<< i << ' '<< j << endl;
			}
		rotate(tmp, players->nowDirect);
		players->activationSensor(tmp);
		players->calculDirect();
	}
	else
		players->buttonListen();
	point *to;
	switch(players->nowDirect)
	{
	case TOP:
		to = &body[head_x-1][head_y];
		head_x--;
		break;
	case RIGHT:
		to = &body[head_x][head_y+1];
		head_y++;
		break;
	case BOTTOM:
		to = &body[head_x+1][head_y];
		head_x++;
		break;
	case LEFT:		
		to = &body[head_x][head_y-1];
		head_y--;
		break;
	}
	players->move(to);
}

bool field::checkBorder(int Row, int Col)
{
	if(Row < 0 || Row >= X || Col < 0 || Col >= X)
		return false;
	return true;
}

ostream &operator << (ostream &stream, field &myField)
{
	for(int i = 0; i<X; i++)
	{
		for(int j = 0; j<X; j++)
			switch(myField.body[i][j].getItem())
			{
			case EAT:
				stream << "*";
				break;
			case WALL:
				stream << "#";
				break;
			case SNAKE:
				stream << "&";
				break;
			case VOID:
				stream << " ";
				break;
			}
		stream << endl;
	}
	return stream;
}