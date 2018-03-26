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
		sf::Sprite	m_sprite;

	public:

		Piece_draw(Type type, Side side, sf::Texture &texture) : Piece(type, side)
		{
			setTexture(type, side, texture);
			m_sprite.setScale(0.3f, 0.3f);
			auto size = m_sprite.getLocalBounds();
			m_sprite.setOrigin(size.width / 2, size.height / 2);
		}

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		void setTexture(Type type, Side side, sf::Texture &texture);

		virtual void setTakenSquare(Square_draw * newSquare);

	};
}