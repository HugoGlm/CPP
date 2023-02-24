#include <iostream>
#include "GamePad/GamePad.h"
#include <conio.h>
#include <format>

int GetCH()
{
	if (_kbhit()) // retourne true si une touche est appuyé
	{
		return _getch(); // renvoie la touche appuyé
	}
	return -1;
}

int main()
{
	char _c = '\t';
	GamePad _pad = GamePad(0);
	float _lTX, _lTY, _rTX, _rTY;
	while (true)
	{
		_c = GetCH();
		if (_c == 'a')
			_pad.SetVibration(60000, 60000);
		else if (_c == 'z')
			_pad.ClearVibration();
		else if (_c == 'e')
			break;
		_pad.Update();
		if (_pad.IsConnected())
		{
			_pad.GetDeltaLeftThumb(_lTX, _lTY);
			_pad.GetDeltaRightThumb(_rTX, _rTY);
			std::cout << std::format("Left: X: {}, Y: {}", _lTX, _lTY) << std::endl;
			std::cout << std::format("Right: X: {}, Y: {}", _rTX, _rTY) << std::endl;
		}
		_c = '\t';
	}
}