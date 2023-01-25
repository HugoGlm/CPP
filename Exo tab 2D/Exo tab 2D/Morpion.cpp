#include <iostream>
#include <Windows.h>
using namespace std;

const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

const int sizeTab = 3;
int shift,
	isPlayer1,
	cursor[2];
string Logo = " _ ";
string Tab[sizeTab][sizeTab] = 
							   {
								{Logo, Logo, Logo},
								{Logo, Logo, Logo},
								{Logo, Logo, Logo},
							   };

void SetTab()
{
	for (int i = 0; i < sizeTab; i++)
	{
		for (int j = 0; j < sizeTab; j++)
		{
			if (cursor[0] == i && cursor[1] == j)
				SetConsoleTextAttribute(_hConsole, 6);// orange
			else
				SetConsoleTextAttribute(_hConsole, 2);// green

			cout << Tab[j][i];
		}
		cout << endl;
	}
	SetConsoleTextAttribute(_hConsole, 7); // white
}
void PlayerTurn()
{
	isPlayer1 = !isPlayer1;
	int _color = (isPlayer1) ? 4 : 3; // 4 = red and 3 = cyan
	SetConsoleTextAttribute(_hConsole, _color);
	cout << " Player " << isPlayer1 << " can move (with z, q, s , d) and press p for place\n";
}
void Move()
{
	char _input;
	cin >> _input;

	PlayerTurn();
	SetTab();

	if(_input == 'z')
		cursor[0] = cursor[0] == 0 ? 0 : cursor[0] - 1;
	else if(_input == 's')
		cursor[0] = cursor[0] == 2 ? 2 : cursor[0] + 1;
	else if(_input == 'q')
		cursor[1] = cursor[1] == 0 ? 0 : cursor[1] - 1;
	else if(_input == 'd')
		cursor[1] = cursor[1] == 2 ? 2 : cursor[1] + 1;
	else if (_input == 'p')
	{
		isPlayer1 = !isPlayer1;
		char _place = (isPlayer1) ? 'X' : 'O';
	}

	system("CLS");
	PlayerTurn();
	SetTab();
	Move();
}

int main()
{
	Move();
}