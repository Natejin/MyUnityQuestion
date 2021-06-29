#pragma once

typedef struct _tagResolution {

	unsigned int width;
	unsigned int height;
	void SetSize(int width, int height) {
		this->width = width;
		this->height = height;
	}
}RESOLUTION, *PRESOLUTION;

typedef struct Vector2 {
    double x;
    double y;

    Vector2() :
        x(0.f), y(0.f) {

    }

    Vector2(double x, double y) :
        x(x), y(y) {

    }

    Vector2(const Vector2& pos) :
        x(pos.x), y(pos.y) {

    }

    //Vector2(const POINT& pt) :
    //    x(pt.x), y(pt.y) {

    //}

    Vector2& operator+=(const Vector2& rhs) {

        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    Vector2& operator-=(const Vector2& rhs) {

        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }

    Vector2& operator-() {
        this->x = -(this->x);
        this->y = -(this->y);
        return *this;
    }

    Vector2 operator +(const Vector2& Other) const
    {
        return Vector2(x + Other.x, y + Other.y);
    }

    Vector2 operator -(const Vector2& Other) const
    {
        return Vector2(x - Other.x, y - Other.y);
    }

    Vector2 operator /(const double& Other) const
    {
        return Vector2(x / Other, y / Other);
    }

    bool operator !=(const Vector2& Other) const
    {
        return (x != Other.x || y != Other.y);
    }

    bool operator ==(const Vector2& Other) const
    {
        return (x == Other.x && y == Other.y);
    }

    void SetRandomVector(Vector2 base, Vector2 random) {
        if (random.x > 0)
        {
            x = base.x + rand() % (int)random.x;
        }
        else {
            x = base.x;
        }
        if (random.y > 0)
        {
            y = base.y + rand() % (int)random.y;
        }
        else {
            y = base.y;
        }
    }
};