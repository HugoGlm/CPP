//#include "ViewReservation.h"
//#include "../../Client/Client.h"
//#include "../../Booking/Manager/BookingManager.h"
//#include <string>
//#include <Windows.h>
//#include <stdlib.h>
//#include <tchar.h>
//#include <CommCtrl.h>
//#include <iostream>
//
//#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
//
//#define IDC_MONTHCAL 101
//#define Height 25
//
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	PAINTSTRUCT ps;
//	HDC hdc;
//	TCHAR title[] = L"Booking View";
//	TCHAR NoBooking[] = L"No Bookings...";
//	switch (uMsg)
//	{
//	case WM_PAINT:
//		hdc = BeginPaint(hwnd, &ps);
//		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
//		TextOut(hdc, 400, 0, title, _tcslen(title));
//		TextOut(hdc, 5, 30, NoBooking, _tcslen(NoBooking));
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hwnd, uMsg, wParam, lParam);
//		break;
//	}
//
//	return 0;
//}
//
//#pragma region methods
//int ViewReservation::CreateWindows()
//{
//	RECT rc;
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
//	HWND ButtonReturn = CreateWindowEx(
//		WS_EX_CLIENTEDGE,
//		L"BUTTON",
//		L"Clique pas ca marche pas"/*"Return"*/,
//		WS_VISIBLE | WS_CHILD,
//		5,						// position x
//		0,						// position y
//		200,					// length
//		Height,					// height
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
//	ShowWindow(handle, SW_SHOWDEFAULT);
//}
//void ViewReservation::ShowReservation()
//{
//	std::vector<Booking*> _bookings = BookingManager::Instance()->Bookings();
//	for (Booking* _booking : _bookings)
//	{
//		std::cout << _bookings << std::endl;
//	}
//}
//void ViewReservation::Execute()
//{
//		CreateWindows();
//		MSG msg = { };
//		while (GetMessage(&msg, NULL, 0, 0) > 0)
//		{
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//	std::cout << "TestView" << std::endl;
//}
//#pragma endregion
//
