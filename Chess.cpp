//Chess.cpp : Defines the entry point for the console application.
//TODO: Implement move constructor for everything, for undo function.

#include "stdafx.h"

#include "Game_drawable.h"
#include "GUI.h"
#include "ResourceManager.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window;
	window.create(sf::VideoMode(800,600), "Chess", sf::Style::Default, settings);
	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(5);
	//window.setActive(false);

	using namespace Chess;

	ResourceManager resources{};

	Game_drawable game(resources, false);
	tgui::Gui gui{ window };

	createUndoButton(gui, game);
	createFlipButton(gui, game);

	game.populateBoard();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				//rozmiarOkna(event.size.width, event.size.height);
				break;
			case sf::Event::MouseButtonPressed:
			{
				switch (event.mouseButton.button)
				{
				case sf::Mouse::Left:
				case sf::Mouse::Right:
				{
					game.onMouseClick(event.mouseButton, window);
					game.onMouseMoved(event.mouseButton.x, event.mouseButton.y, window);
				}
				}
				break;
			}
			case sf::Event::KeyPressed:
			{
				switch (event.key.code)
				{
					//Show squares attacked by white
				case sf::Keyboard::W:
					game.unhighlightAll();
					game.highlight(game.getAttackedSquares(Side::White), sf::Color::Red);
					break;
					//Show squares attacked by black
				case sf::Keyboard::B:
					game.unhighlightAll();
					game.highlight(game.getAttackedSquares(Side::Black), sf::Color::Red);
					break;
				case sf::Keyboard::Z:
					game.undo();
					break;
				case sf::Keyboard::F:
					game.flipBoard();
					break;
				}
				break;
			}
			case sf::Event::MouseMoved:
			{
				game.onMouseMoved(event.mouseMove.x, event.mouseMove.y, window);
				break;
			}
			}
			gui.handleEvent(event);
		}

		//Animate all piece sprites
		game.animate();

		window.clear(sf::Color::Black);

		window.draw(game);

		gui.draw();

		window.display();
	}

    return 0;
}

