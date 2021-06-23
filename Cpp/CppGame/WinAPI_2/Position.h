struct Position {
	double x = 0;
	double y = 0;
	Position();
	Position(double xAxis, double yAxis);

	bool operator !=(const Position& Other) const
	{
		return (x != Other.x || y != Other.y);
	}

	bool operator ==(const Position& Other) const
	{
		return (x == Other.x && y == Other.y);
	}

	Position operator +(const Position& Other) const
	{
		return Position(x + Other.x, y + Other.y);
	}

	Position operator -(const Position& Other) const
	{
		return Position(x - Other.x, y - Other.y);
	}
};