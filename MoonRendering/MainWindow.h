#pragma once

#include "stdafx.h"

class MainWindow {
public:
	//Handle Window
	HWND mHwnd = NULL;
	
	HINSTANCE mhInstance;

	// name of the window (not the title)
	//LPCTSTR windowName;

	// title of the window
	//LPCTSTR windowTitle = L"Moon";

	int mWidth = 800;
	int mHeight = 600;

	//nCmdShow : Controls how the window is to be shown.
	HRESULT InitializeWindow(HINSTANCE hinstance, int nCmdShow, PCWSTR pszWindowName);

	//callback function for window message
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	//Get Window Name
	PCWSTR GetWindowClassName() const;
};
