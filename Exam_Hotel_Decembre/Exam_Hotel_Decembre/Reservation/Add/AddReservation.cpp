#include "AddReservation.h"
#include "AddReservation.h"
#include "../../Client/Client.h"
#include "../../Booking/Manager/BookingManager.h"
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <tchar.h>
#include <CommCtrl.h>
#include <iostream>

#pragma warning(disable: 4996)

#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#define IDC_MONTHCAL 101
#define Height 25

void AddReservation::Text()
{
	HDC hdc = { };
	TCHAR title[] = L"Create New Booking";
	TCHAR firstName[] = L"Enter first name: ";
	TCHAR lastName[] = L"Enter last Name: ";
	TCHAR nbrPeople[] = L"For how many people: ";

	TextOut(hdc, 400, 0, title, _tcslen(title));
	TextOut(hdc, 5, 80, firstName, _tcslen(firstName));
	TextOut(hdc, 5, 110, lastName, _tcslen(lastName));
	TextOut(hdc, 5, 160, nbrPeople, _tcslen(nbrPeople));
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	
	switch (uMsg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		AddReservation::Text();
		EndPaint(hwnd, &ps);
		break;
	case WM_COMMAND:
		std::cout << "je t'avais prevenu" << std::endl;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	}
}
#pragma region methods
int AddReservation::CreateWindows()
{
	RECT rc;
	HINSTANCE hInstance = nullptr;

	const wchar_t CLASS_NAME[] = L"Sample Window Class";

	WNDCLASS wc = { };

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	HWND handle = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,
		CLASS_NAME,
		L"Hotel Application",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		1000, 500,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	HWND EditFisrtName = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		L"EDIT",
		L"fisrt name...",
		WS_VISIBLE | WS_CHILD,
		140,					// position x
		80,						// position y
		200,					// length
		Height,					// height
		handle,					// class parent
		NULL,
		hInstance,
		NULL
	);
	HWND EditLastName = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		L"EDIT",
		L"last name...",
		WS_VISIBLE | WS_CHILD,
		140,					// position x
		110,					// position y
		200,					// length
		Height,					// height
		handle,					// class parent
		NULL,
		hInstance,
		NULL
	);
	HWND EditPeople = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		L"EDIT",
		L"2",
		WS_VISIBLE | WS_CHILD,
		180,					// position x
		160,					// position y
		200,					// length
		Height,					// height
		handle,					// class parent
		NULL,
		hInstance,
		NULL
	);
	HWND calendar = CreateWindowEx(0,
		MONTHCAL_CLASS,
		L"",
		WS_BORDER | WS_CHILD | WS_VISIBLE | MCS_NOTODAYCIRCLE | MCS_NOTODAY | MCS_MULTISELECT,
		5,						// position x
		200,					// position y
		215,					// length
		145,					// height
		handle,					// class parent
		(HMENU)IDC_MONTHCAL,
		hInstance,
		NULL
	);
	// multiselect limiter a 31
	MonthCal_SetMaxSelCount(calendar, 31);

	// range pour ne pas acceder au date passer
	SYSTEMTIME _today[1] = { };
	MonthCal_GetToday(calendar, _today);
	MonthCal_SetRange(calendar, GDTR_MIN, _today);

	MonthCal_GetMinReqRect(calendar, &rc);
	
	MonthCal_SetCurrentView(calendar, MCMV_MONTH);

	HWND ButtonReturn = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		L"BUTTON",
		L"Clique pas ca marche pas"/*"Return"*/,
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		5,						// position x
		0,						// position y
		200,					// length
		Height,					// height
		handle,					// class parent
		NULL,
		hInstance,
		NULL
	);
	HWND ButtonSave = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		L"BUTTON",
		L"Clique pas ca marche pas"/*"Save Booking"*/,
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		10,						// position x
		370,					// position y
		200,					// length
		Height,					// height
		handle,					// class parent
		NULL,
		hInstance,
		NULL
	);
	if (!handle)
	{
		MessageBox(NULL,
			L"Call to CreateWindowEx failed!",
			L"Windows Desktop Guided Tour",
			NULL);

		return 1;
	}
	ShowWindow(handle, SW_SHOW);
}
void AddReservation::Reservation()
{
	const std::string _firstName = "";
	const std::string _lastName = "";
	const int _people = 0;
	try
	{
		Client* _client = new Client(_firstName, _lastName, _people);
		BookingManager::Instance()->AddBooking(new Booking(_client));
	}
	catch (const std::exception& _exception)
	{
		std::cout << _exception.what() << std::endl;
	}
}
void AddReservation::Execute()
{
	CreateWindows();
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
#pragma endregion