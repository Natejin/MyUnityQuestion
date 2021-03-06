#pragma once
#include <math.h>

struct Vector2
{
    double x, y;

    Vector2() { x = 0; y = 0; }
    Vector2(double x, double y) :x(x), y(y) {};


    bool operator !=(const Vector2& rhs) const
    {
        return (x != rhs.x || y != rhs.y);
    }

    bool operator ==(const Vector2& rhs) const
    {
        return (x == rhs.x && y == rhs.y);
    }

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

    Vector2 operator +(const Vector2& rhs) const
    {
        return Vector2(x + rhs.x, y + rhs.y);
    }

    Vector2 operator -(const Vector2& rhs) const
    {
        return Vector2(x - rhs.x, y - rhs.y);
    }

    Vector2 operator *(const Vector2& rhs) const
    {
        return Vector2(x * rhs.x, y * rhs.y);
    }

    Vector2 operator /(const Vector2& rhs) const
    {
        return Vector2(x / rhs.x, y / rhs.y);
    }

    Vector2 operator *(const double& rhs) const
    {
        return Vector2(x * rhs, y * rhs);
    }

    Vector2 operator /(const double& rhs) const
    {
        return Vector2(x / rhs, y / rhs);
    }

    void SetPos(double _x, double _y);
    float Length();
    Vector2 Normalize();
    float Dot(Vector2& v1, Vector2& v2);
};