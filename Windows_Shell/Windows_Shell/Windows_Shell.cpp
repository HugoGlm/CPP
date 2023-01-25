#include <iostream>
#include <string>
#include <Windows.h>
#include <commctrl.h>

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

int CreateWindows()
{
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

		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

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
		70,			// position x
		120,			// position y
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
		L"Ok",
		WS_VISIBLE | WS_CHILD,
		70,			// position x
		140,			// position y
		40,			// length
		20,			// height
		handle,		// class parent
		NULL,
		hInstance,
		NULL
	);

	HWND handleToolBar = CreateWindowExW(
		WS_EX_CLIENTEDGE,
		TOOLBARCLASSNAME,
		L"",
		WS_VISIBLE | WS_CHILD | TBSTYLE_WRAPABLE,
		0,			// position x
		0,			// position y
		0,			// length
		0,			// height
		handle,		// class parent
		NULL,
		hInstance,
		NULL
	);

	const int numButtons = 3;
	TBBUTTON tbButtons[numButtons] =
	{
		{ NULL, NULL, TBSTATE_ENABLED, BTNS_AUTOSIZE, {0}, 0, (INT_PTR)L"File"},
		{ NULL, NULL, TBSTATE_ENABLED, BTNS_AUTOSIZE, {0}, 0, (INT_PTR)L"Edit"},
		{ NULL, NULL, TBSTATE_ENABLED, BTNS_AUTOSIZE, {0}, 0, (INT_PTR)L"View"}
	};

	// Add buttons.
	SendMessage(handleToolBar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0);
	SendMessage(handleToolBar, TB_ADDBUTTONS, (WPARAM)numButtons, (LPARAM)&tbButtons);

	// Resize the toolbar, and then show it.
	SendMessage(handleToolBar, TB_AUTOSIZE, 0, 0);
	ShowWindow(handleToolBar, TRUE);

	if (handle == NULL /*|| handleEdit == NULL || handleButton == NULL || handleToolBar == NULL*/)
		return 0;

	ShowWindow(handle, SW_SHOWDEFAULT);
}

int main()
{
	CreateWindows();
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}