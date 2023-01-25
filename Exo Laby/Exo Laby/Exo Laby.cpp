#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
const HANDLE _hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

#pragma region parameter
const int sizeLaby = 6;
string map[sizeLaby] =
                {
                    "#######S#######",
                    "##   ## ##  ###",
                    "## ####    ####",
                    "##     ### ####",
                    "######     ####",
                    "######E########"
                };
int player[2] = {5, 6};
int out[2] = {0, 7};
#pragma endregion
#pragma region proto
void SetLaby();
void MovePlayer();
void Win();
#pragma endregion

void SetLaby()
{
    string laby = "";
    for (int i = 0; i < sizeLaby; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            SetConsoleTextAttribute(_hconsole, 6);
            if (player[0] == i && player[1] == j)
                laby += "P";
            else if (out[0] && out[1])
                laby += "S";
            else
                laby += map[i][j];
        }
        laby += "\n";
    }
    cout << laby << endl;
}
void MovePlayer()
{
    cout << "Move with Z, Q, S, D : ";
    char _input;
    cin >> _input;

    SetLaby();

    if (_input == 'z')
    {
        if(map[player[0] - 1][player[1]] != '#')
            player[0] = player[0] == 0 ? 0 : player[0] - 1;
    }
    else if (_input == 's')
    {
        if (map[player[0] + 1][player[1]] != '#')
            player[0] = player[0] == 5 ? 5 : player[0] + 1;
    }
    else if (_input == 'q')
    {
        if (map[player[0]][player[1] - 1] != '#')
        player[1] = player[1] == 0 ? 0 : player[1] - 1;
    }
    else if (_input == 'd')
    {
        if (map[player[0]][player[1] + 1] != '#')
        player[1] = player[1] == 15 ? 15 : player[1] + 1;
    }

    system("CLS");
    SetLaby();
    Win();
}
void Win()
{
    if (player[0] == out[0] && player[1] == out[1])
        cout << "GG you win !!";
    else
        MovePlayer();
}
int main()
{
    SetLaby();
    MovePlayer();
}