#pragma once
#include "Window.h"

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();

	Window* GetWindow() { return &_window; };

private:
	Window _window;
};

