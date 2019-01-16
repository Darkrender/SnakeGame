#include "pch.h"
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	//sf::RenderWindow window(sf::VideoMode(800, 600), "First Window");
	Game game;

	while (!game.GetWindow()->IsDone())
	{
		game.HandleInput();
		game.Update();
		game.Render();
	}

	return 0;
}
