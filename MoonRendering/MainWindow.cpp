#include "MainWindow.h"

HRESULT MainWindow::InitializeWindow(HINSTANCE hinstance, int nCmdShow, PCWSTR pszWindowName)
{

    //WNDCLASSEX : window informations
	WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = MainWindow::WindowProc;
    wc.cbClsExtra = NULL;
    wc.cbWndExtra = NULL;
    wc.hInstance = hinstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = GetWindowClassName();
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    //register wc
    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, L"Error registering class",
            L"Error", MB_OK | MB_ICONERROR);
        return E_FAIL;
    }
 
    //Create Window and store
    mHwnd = CreateWindow(
        GetWindowClassName(),
        pszWindowName,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        mWidth, mHeight,
        nullptr, nullptr,
        hinstance, this
    );

    if (!mHwnd)
    {
        MessageBox(NULL, L"Error creating window",
            L"Error", MB_OK | MB_ICONERROR);
        return E_FAIL;
    }

    // show window and update
    ShowWindow(mHwnd, SW_SHOW);
    //UpdateWindow(mHwnd);

    return S_OK;
}

LRESULT CALLBACK MainWindow::WindowProc(HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (msg)
    {

    case WM_KEYDOWN:
        if (wParam == VK_ESCAPE) {
            if (MessageBox(0, L"Are you sure you want to exit?",
                L"Really?", MB_YESNO | MB_ICONQUESTION) == IDYES)
                DestroyWindow(hwnd);
        }
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd,  
        msg,
        wParam,
        lParam);
}

PCWSTR MainWindow::GetWindowClassName() const
{
    return L"The Moon Window Class";
}