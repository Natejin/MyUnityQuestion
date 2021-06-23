#pragma once
class Scale
{
	double x = 0;
	double y = 0;
	Scale();
	Scale(double xAxis, double yAxis);

	bool operator !=(const Scale& Other) const
	{
		return (x != Other.x || y != Other.y);
	}

	bool operator ==(const Scale& Other) const
	{
		return (x == Other.x && y == Other.y);
	}

	Scale operator +(const Scale& Other) const
	{
		return Scale(x + Other.x, y + Other.y);
	}

	Scale operator -(const Scale& Other) const
	{
		return Scale(x - Other.x, y - Other.y);
	}
};

