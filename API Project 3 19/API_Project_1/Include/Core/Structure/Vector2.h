#pragma once
#include <math.h>
#include <Windows.h>

typedef struct Vector2
{
    double x, y;

    Vector2() { x = 0; y = 0; }
    Vector2(double x, double y) :x(x), y(y) {};

    Vector2 PosFront(double x) {
        this->x += x;
        return *this;
    }

    Vector2 PosBack(double x) {
        this->x -= x;
        return *this;
    }

    Vector2 PosUp(double y) {
        this->y -= y;
        return *this;
    }

    Vector2 PosDown(double y) {
        this->y += y;
        return *this;
    }

    void operator =(const Vector2& rhs)
    {
        x = rhs.x;
        y = rhs.y;
    }

    void operator =(const POINT& rhs)
    {
        x = rhs.x;
        y = rhs.y;
    }

    bool operator !=(const Vector2& rhs) const
    {
        return (x != rhs.x || y != rhs.y);
    }

    bool operator ==(const Vector2& rhs) const
    {
        return (x == rhs.x && y == rhs.y);
    }

    void operator+=(const Vector2& rhs) {

        this->x += rhs.x;
        this->y += rhs.y;
    }

    void operator-=(const Vector2& rhs) {

        this->x -= rhs.x;
        this->y -= rhs.y;
    }

    Vector2& operator-()
    {
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

    Vector2 operator *(const float& rhs) const
    {
        return Vector2(x * (double)rhs, y * (double)rhs);
    }

    Vector2 operator /(const float& rhs) const
    {
        return Vector2(x / rhs, y / rhs);
    }

    void SetPos(double _x, double _y);
    double Length();
    Vector2 Normalize();
    double Dot(Vector2& v1, Vector2& v2);
}POSITION, *PPOSITION;