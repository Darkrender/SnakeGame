#pragma once
#include "SFML/Graphics.hpp"

class Window
{
public:
	Window();
	Window(const std::string& windowTitle, const sf::Vector2u& windowSize);
	~Window();

	void Update();
	void ToggleFullscreen();
	void BeginDraw();
	void EndDraw();
	void Draw(const sf::Drawable& drawable);

	bool IsDone() { return _isDone; }
	bool IsFullscreen() { return _isFullscreen; }

	sf::RenderWindow* GetRenderWindow() { return &_window; };
	sf::Vector2u GetWindowSize() { return _windowSize; }

private:
	void Setup(const std::string& windowTitle, const sf::Vector2u& windowSize);
	void Create();
	void Destroy();

	sf::RenderWindow _window;
	sf::Vector2u _windowSize;
	std::string _windowTitle;

	bool _isDone;
	bool _isFullscreen;
};

