#pragma once

#include "Direction.h"
#include "Piece.h"

namespace Chess
{

	class Game_drawable;
	class Square_draw;

	class Piece_draw :
		public Piece,
		virtual public sf::Drawable
	{
	private:
		sf::Sprite		m_sprite;

	public:

		Piece_draw(Type type, Side side, int id, Game & parent, const sf::Texture &texture);

		Piece_draw(const Piece & piece, Game & parent, const sf::Texture &texture);

		void animate();

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		void setTexture(const sf::Texture & texture);
		void setTextureRect();

		virtual void setTakenSquare(Position &position, bool isMove = true) override;

		virtual void promote(Type type) override;

		void teleport(Position &position, bool isMove = false);

		void teleport();

		void fade(bool fade);
	};
}