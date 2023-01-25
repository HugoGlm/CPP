//#include "Menu.h"
//#include "../Reservation/Add/AddReservation.h"
//#include "../Reservation/View/ViewReservation.h"
//#include <iostream>
//#include <string>
//#include <Windows.h>
//#include <stdlib.h>
//#include <tchar.h>
//#include <CommCtrl.h>
//
//#define HEIGHT 25
//
//void Menu::Text()
//{
//	HDC hdc = { };
//	TCHAR title[] = L"Hotel Objectif3D";
//
//	TextOut(hdc, 400, 0, title, _tcslen(title));
//}
//LRESULT CALLBACK /*Menu::*/WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//
//	switch (uMsg)
//	{
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
//		Menu::Text();
//		EndPaint(hwnd, &ps);
//		break;
//	case WM_COMMAND:
//		std::cout << "je t'avais prevenu" << std::endl;
//		break;
//		// les boutons affiche bien le texte quand il sont clique mais il le font tous j'arrive pas a faire que deux bouton soit independant
//	default:
//		return DefWindowProc(hwnd, uMsg, wParam, lParam);
//		break;
//	}
//	return 0;
//}
//#pragma region methods
//int Menu::CreateWindows()
//{
//	HINSTANCE hInstance = nullptr;
//
//	const wchar_t CLASS_NAME[] = L"Sample Window Class";
//
//	WNDCLASS wc = { };
//
//	wc.lpfnWndProc = WindowProc;
//	wc.hInstance = hInstance;
//	wc.lpszClassName = CLASS_NAME;
//
//	RegisterClass(&wc);
//
//	HWND handle = CreateWindowEx(
//		WS_EX_OVERLAPPEDWINDOW,
//		CLASS_NAME,
//		L"Hotel Application",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, CW_USEDEFAULT,
//		1000, 500,
//		NULL,
//		NULL,
//		hInstance,
//		NULL
//	);
//	HWND ButtonAdd = CreateWindowEx(
//		WS_EX_CLIENTEDGE,
//		L"BUTTON",
//		L"Clique pas ca marche pas"/*"create new Booking"*/,
//		WS_VISIBLE | WS_CHILD,
//		100,					// position x
//		30,						// position y
//		200,					// length
//		HEIGHT,					// height
//		handle,					// class parent
//		NULL,
//		hInstance,
//		NULL
//	);
//	HWND ButtonView = CreateWindowEx(
//		WS_EX_CLIENTEDGE,
//		L"BUTTON",
//		L"Clique pas ca marche pas"/*"View all Bookings"*/,
//		WS_VISIBLE | WS_CHILD,
//		300,					// position x
//		30,						// position y
//		200,					// length
//		HEIGHT,					// height
//		handle,					// class parent
//		NULL,
//		hInstance,
//		NULL
//	);
//	if (!handle)
//	{
//		MessageBox(NULL,
//			L"Call to CreateWindowEx failed!",
//			L"Windows Desktop Guided Tour",
//			NULL);
//
//		return 1;
//	}
//	ShowWindow(handle, SW_SHOW);
//	UpdateWindow(handle);
//}
//void Menu::Execute()
//{
//	CreateWindows();
//	MSG msg = { };
//	while (GetMessage(&msg, NULL, 0, 0) > 0)
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//}
//#pragma endregion