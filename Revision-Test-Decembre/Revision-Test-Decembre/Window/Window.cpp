#include <iostream>
#include <string>
#include <Windows.h>
#include <commctrl.h>
#include "Window.h"

HINSTANCE hInstance = nullptr;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_PAINT)
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		// All painting occurs here, between BeginPaint and EndPaint.

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int Window::CreateWindows()
{
	HINSTANCE hInstance = nullptr;

	const wchar_t CLASS_NAME[] = L"Sample Window Class";

	WNDCLASS wc = { };

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	HWND handle = CreateWindowExW(
		NULL,
		CLASS_NAME,
		L"Learn to Program Windows",
		WS_OVERLAPPEDWINDOW,

		CW_USEDEFAULT, CW_USEDEFAULT, 500, 150,

		NULL,
		NULL,
		hInstance,
		NULL
	);

	HWND handleEdit = CreateWindowExW(
		WS_EX_CLIENTEDGE,
		L"EDIT",
		L"",
		WS_VISIBLE | WS_CHILD,
		0,			// position x
		10,			// position y
		150,		// length
		20,			// height
		handle,		// class parent
		NULL,
		hInstance,
		NULL
	);
	HWND handleButton = CreateWindowExW(
		WS_EX_CLIENTEDGE,
		L"BUTTON",
		L"Valid",
		WS_VISIBLE | WS_CHILD,
		0,			// position x
		30,			// position y
		40,			// length
		20,			// height
		handle,		// class parent
		NULL,
		hInstance,
		NULL
	);
	if (!handle)
	{
		MessageBox(NULL,
			L"Hello!",
			L"Test",
			NULL);

		return 1;
	}
	ShowWindow(handle, SW_SHOWDEFAULT);
}

void Window::Execute()
{
	CreateWindows();
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
