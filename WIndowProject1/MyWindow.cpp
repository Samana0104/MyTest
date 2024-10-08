#include "MyWindow.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM
	lParam);

void MyWindow::CreateRegisterClass()
{
	WNDCLASS wc = { };
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = this->hInstance;
	wc.lpszClassName = this->windowClassName.c_str();
	RegisterClass(&wc);
}

bool MyWindow::CreateWin(UINT startX, UINT startY, UINT width, UINT height)
{
	CreateRegisterClass();

	HWND hwnd = CreateWindowEx(
		0, // Optional window styles.
		this->windowClassName.c_str(),
		L"Learn to Program Windows", // Window text
		WS_OVERLAPPEDWINDOW,// Window style
		// Size and position
		startX, startY,
		width, height,
		NULL, // Parent window
		NULL, // Menu
		hInstance, // Instance handle
		NULL // Additional application data
	);

	if (hwnd == NULL)
		return false;
	this->hWnd = hwnd;

	ShowWindow(hwnd, SW_SHOW);
	return true;
}

void MyWindow::WindowRun()
{
	MSG msg = { };
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			GameRun();
		}
	}
	return;
}

void MyWindow::GameRun()
{
	int a = 7;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM
	lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

