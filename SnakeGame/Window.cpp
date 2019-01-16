#include "pch.h"
#include "Window.h"

Window::Window()
{
	Setup("Default Window", sf::Vector2u(800, 600));
}

Window::Window(const std::string& windowName, const sf::Vector2u& windowSize)
{
	Setup(windowName, windowSize);
}

Window::~Window()
{
	Destroy();
}

void Window::Setup(const std::string& windowName, const sf::Vector2u& windowSize)
{
	_windowSize = windowSize;
	_windowTitle = windowName;
	_isFullscreen = false;
	_isDone = false;
	Create();
}

void Window::Create()
{
	auto style = _isFullscreen ? sf::Style::Fullscreen : sf::Style::Default;

	_window.create(sf::VideoMode(_windowSize.x, _windowSize.y), _windowTitle, style);
}

void Window::Destroy()
{
	_window.close();
}

void Window::Update()
{
	sf::Event event;

	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_isDone = true;
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
		{
			ToggleFullscreen();
		}
	}
}

void Window::ToggleFullscreen()
{
	_isFullscreen = !_isFullscreen;

	Destroy();
	Create();
}

void Window::BeginDraw()
{
	_window.clear();
}

void Window::Draw(const sf::Drawable& drawable)
{
	_window.draw(drawable);
}

void Window::EndDraw()
{
	_window.display();
}
