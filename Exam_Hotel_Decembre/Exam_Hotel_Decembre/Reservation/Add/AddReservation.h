#pragma once
#include "../../Object/Object.h"

class AddReservation //: public Object
{
#pragma region methods
public:
	static void Text();
	static int CreateWindows();
	static void Reservation();
	static void Execute();
#pragma endregion
#pragma region override
public:
	//virtual LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) override;
#pragma endregion

};

