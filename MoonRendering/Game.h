#pragma once

#include "stdafx.h"

#include "MainWindow.h"

namespace library 
{
	class Game
	{
	public:
		Game(_In_ PCWSTR pszGameName);
		Game(const Game& other) = delete;
		Game(Game&& other) = delete;
		Game& operator=(const Game& other) = delete;
		Game& operator=(Game&& other) = delete;
		~Game() = default;

		HRESULT Initialize(_In_ HINSTANCE hInstance, _In_ INT nCmdShow);

		INT Run();

		PCWSTR GetGameName() const;

	private:
		PCWSTR m_pszGameName;
		std::unique_ptr<MainWindow> m_mainWindow;
		//std::unique_ptr<Renderer> m_renderer;
	};


}