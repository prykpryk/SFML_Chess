//Chess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Game.h"


int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window;
	window.create(sf::VideoMode(800,600), "Chess", sf::Style::Default, settings);
	window.setVerticalSyncEnabled(true);
	//window.setActive(false);

	using namespace Chess;

	Game board;

	board.populateBoard();

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
				{
					board.onMouseClick(event.mouseButton, window);
				}
				}
			}
			}
		}

		window.clear(sf::Color::Black);

		window.draw(board);

		window.display();
	}

    return 0;
}

