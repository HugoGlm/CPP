#pragma once
#include "Object.h"
#include "MorpionBoard.h"
#include <vector>
#include <vector>

class MorpionAI : public Object
{
#pragma region constructor
public:
	MorpionAI() = default;
	~MorpionAI() = default;
#pragma endregion
#pragma region methods
private:
	int MinMax(std::vector<int> _board, int _player);
public:
	int BestMove(MorpionBoard _board);
#pragma endregion
};

