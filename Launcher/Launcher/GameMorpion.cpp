#include <Windows.h>
#include "GameMorpion.h"
#include "Utils.h"

#pragma region constructor
GameMorpion::GameMorpion(const bool& _isFirstPlayer)
{
	isFirstPlayer = _isFirstPlayer;
}
GameMorpion::GameMorpion(const GameMorpion& _copy)
{
	isFirstPlayer = _copy.isFirstPlayer;
}
#pragma endregion
#pragma region methods
void GameMorpion::ReadBoard()
{
	for (int y = 0; y < 3; y++)
	{
		std::string _tmp;
		for (int x = 0; x < 7; x++)
		{
			_tmp += board[y][x];
		}
		std::cout << _tmp << std::endl;
	}
}
void GameMorpion::ColorConsole()
{
	int _color = isFirstPlayer ? 3 : 5;
	const HANDLE _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_hConsole, _color);
}
void GameMorpion::SetNextPlayer()
{
	isFirstPlayer = !isFirstPlayer;
}
void GameMorpion::ChoosePlace()
{
	int _input;
	std::cin >> _input;

	switch (_input)
	{
	case 1:
		if(isFirstPlayer)
			Utils::Replace(board[2][1], ' ', 'X');
		else if (!isFirstPlayer)
			Utils::Replace(board[2][1], ' ', 'O'); 
		break;
	case 2:
		if (isFirstPlayer)
			Utils::Replace(board[2][3], ' ', 'X');
		else if (!isFirstPlayer)
			Utils::Replace(board[2][3], ' ', 'O');
		break;
	case 3:
		if (isFirstPlayer)
			Utils::Replace(board[2][5], ' ', 'X');
		else if (!isFirstPlayer)
			Utils::Replace(board[2][5], ' ', 'O');
		break;
	case 4:
		if (isFirstPlayer)
			Utils::Replace(board[1][1], ' ', 'X');
		else if (!isFirstPlayer)
			Utils::Replace(board[1][1], ' ', 'O');
		break;
	case 5:
		if (isFirstPlayer)
			Utils::Replace(board[1][3], ' ', 'X');
		else if (!isFirstPlayer)
			Utils::Replace(board[1][3], ' ', 'O');
		break;
	case 6:
		if (isFirstPlayer)
			Utils::Replace(board[1][5], ' ', 'X');
		else if (!isFirstPlayer)
			Utils::Replace(board[1][5], ' ', 'O');
		break;
	case 7:
		if (isFirstPlayer)
			Utils::Replace(board[0][1], ' ', 'X');
		else if (!isFirstPlayer)
			Utils::Replace(board[0][1], ' ', 'O');
		break;
	case 8:
		if (isFirstPlayer)
			Utils::Replace(board[0][3], ' ', 'X');
		else if (!isFirstPlayer)
			Utils::Replace(board[0][3], ' ', 'O');
		break;
	case 9:
		if (isFirstPlayer)
			Utils::Replace(board[0][5], ' ', 'X');
		else if (!isFirstPlayer)
			Utils::Replace(board[0][5], ' ', 'O');
		break;
	default:
		break;
	}
}
void GameMorpion::Start()
{
	ReadBoard();
	ChoosePlace();
}
#pragma endregion