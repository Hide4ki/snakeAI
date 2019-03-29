#include <iostream>
#include <Windows.h>
#include "field.h"
#include <time.h>
#include <conio.h>
using namespace std;

int main(void)
{
	field myField;
	unsigned cnt = 0;
	srand(time(NULL));
	try
	{
		while(1)
		{
			Sleep(100);
			system("cls");
			if(!(cnt%5))
				myField.createEat();
			cout << myField;
			myField.nextRound();
			cnt++;
		}
	}
	catch(char *e)
	{
		cout << e;
	}
	system("pause");
	return 0;
}