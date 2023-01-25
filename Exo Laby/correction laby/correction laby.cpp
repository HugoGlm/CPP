#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
#pragma region f/p
const int mapSize = 6;
const char exitValue = 's', player = 'p', enter = 'e', wall = '#';
int currentY = 0,
    currentX = 0;
char currentInput = 'a';

char** t = new char* [10];
for (int i = 0; i < 10; i++)
{
    t[i] = new char(0);  //cree un char de valeur 0 ou 'a' si on ceut new char ('a')
    t[i] = new char[10]; // cree un nouveau tab de 10
}

delete[] t;

string map[mapSize] =
                {
                    "#######s#######",
                    "##   ## ##  ###",
                    "## ####    ####",
                    "##     ### ####",
                    "######     ####",
                    "######e########"
                };
#pragma endregion
#pragma region Proto
bool Init();
void Display();
void GameLoop();
void ReadInput();
void GetNextMove();
void GetInputValue();
#pragma endregion

bool Init()
{
    for (int y = 0; y < mapSize; y++)
    {
        const int length = map[y].length();
        for (int x = 0; x < length; x++)
        {
            if (map[y][x] == 'e')
            {
                currentY = y;
                currentX = x;
                return true;
            }

        }
    }
    return false;
}
void Display()
{
    for (int y = 0; y < mapSize; y++)
    {
        const int length = map[y].length();
        for (int x = 0; x < length; x++)
        {
            if (currentX == x && currentY == y)
                cout << player;
            else
                cout << map[y][x];
        }
        cout << endl;
    }
}
void GameLoop()
{
    while (map[currentY][currentX] != exitValue)
    {
        system("cls");
        Display();
        ReadInput();
        GetInputValue();
    }
}
void ReadInput()
{
    bool _isValidInput = false;
    cout << "Choose direction with z, q, s, d" << endl;
    while (!_isValidInput)
    {
        cin >> currentInput;
        currentInput = tolower(currentInput);
        _isValidInput = currentInput == 'z' || currentInput == 'q' || currentInput == 's' || currentInput == 'd';
    }
}
bool GetNextMove(int _y, int _x)
{
    const bool _yOutOfRange = _y < 0 || _y > mapSize;
    const bool _xOutOfRange = _x < 0 || _x > map[_y].length();
    if (_yOutOfRange || _xOutOfRange) 
        return false;
    return map[_y][_x] != wall;
}
void GetInputValue()
{
    if (currentInput == 'z' && GetNextMove(currentY - 1, currentX))
        currentY--;
    else if (currentInput == 's' && GetNextMove(currentY + 1, currentX))
        currentY++;
    else if (currentInput == 'q' && GetNextMove(currentY, currentX - 1))
        currentX--;
    else if (currentInput == 'd' && GetNextMove(currentY, currentX + 1))
        currentX++;
}
int main()
{
    if (!Init())
        return -2;
    Display();
    GameLoop();
    system("cls");
    cout << "felicitation !" << endl;
}