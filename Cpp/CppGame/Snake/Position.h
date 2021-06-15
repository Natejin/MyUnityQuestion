#pragma once


struct Position {
	int x = 0;
	int y = 0;

	Position();
	Position(int xAxis, int yAxis);

	bool operator !=(const Position& Other) const
	{
		return (x != Other.x || y != Other.y);
	}
};

