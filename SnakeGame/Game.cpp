#include "pch.h"
#include "Game.h"


Game::Game() : _window("SnakeGame", sf::Vector2u(800, 600))
{
}


Game::~Game()
{
}

void Game::Update()
{
	_window.Update();
}

void Game::Render()
{
	_window.BeginDraw();

	_window.EndDraw();
}


void Game::HandleInput()
{

}
