#include "Game.h"

namespace library {

	Game::Game(_In_ PCWSTR pszGameName)
		: m_pszGameName(pszGameName),
		m_mainWindow(std::make_unique<MainWindow>())
	{

	}

	HRESULT Game::Initialize(_In_ HINSTANCE hInstance, _In_ INT nCmdShow)
	{
		HRESULT hr = S_OK;

		hr = (m_mainWindow->InitializeWindow(hInstance, nCmdShow, m_pszGameName));
		if (FAILED(hr))
		{
			MessageBox(0, L"Window Initialization - Failed In Game",
				L"Error", MB_OK);
			return hr;
		}
	}

	INT Game::Run()
	{
		MSG msg = { 0 };
		while (WM_QUIT != msg.message)
		{
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				//Rendering
			}
		}

		return static_cast<INT>(msg.wParam);
	}
}