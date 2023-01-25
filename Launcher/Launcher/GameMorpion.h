#pragma once
#include <iostream>
#include <string>
#include <vector>

class GameMorpion
{
#pragma region f/p
private:
	std::string board[3][7] = { {"|"," ","|"," ","|"," ","|"},
								{"|"," ","|"," ","|"," ","|"},
								{"|"," ","|"," ","|"," ","|"}
						      };
	bool isFirstPlayer = true;
#pragma endregion         
#pragma region constructor
public:
	GameMorpion() = default;
	GameMorpion(const bool& _isFirstPlayer);
	GameMorpion(const GameMorpion& _copy);
#pragma endregion 
#pragma region methods
public:
	void ReadBoard();
	void ColorConsole(); 
	void SetNextPlayer();
	void ChoosePlace();
	void Start();
#pragma endregion
};

