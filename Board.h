#pragma once

#include "Square.h"
#include <array>

namespace Chess 
{
	class Row 
		:public std::array<Square, 8>
	{
	private:
		std::array<Square, 8> squares;
	public:
		Square & operator[](const int index)
		{
			return at(index);
		}

		const Square & operator[](const int index) const
		{
			return at(index);
		}

	};

	class Board
		: public std::array<Row,8>
	{
		Row & operator[](const int index)
		{
			return at(index);
		}

		const Row & operator[](const int index) const
		{
			return at(index);
		}
	};
}

