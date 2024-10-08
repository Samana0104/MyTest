#pragma once
#include <Windows.h>
#include <string>

class MyWindow
{
	virtual void GameRun();
	void CreateRegisterClass();
public:
	std::wstring windowClassName;
	std::wstring windowName;
	HINSTANCE hInstance;
	HWND hWnd;

	MyWindow(HINSTANCE _hInstance, std::wstring _windowName, std::wstring _windowClassName = L"Test") :
		windowName(_windowName),
		hInstance(_hInstance),
		windowClassName(_windowClassName)
	{ }
	bool CreateWin(UINT startX, UINT startY, UINT width, UINT height);
	void WindowRun();
};
