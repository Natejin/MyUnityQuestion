#pragma once
#include "../../Enum.h"

struct Color
{
    Color(int r, int g, int b) :r(r), g(g), b(b) {};
    Color() :r(0), g(0), b(0) {};
    ~Color() {};
    int r, g, b;

    /*void Random() {
        r = RandomManager::GetSingleton()->GetInt(256);
        g = RandomManager::GetSingleton()->GetInt(256);
        b = RandomManager::GetSingleton()->GetInt(256);
    }*/

    Color GetColor(COLOR color) {
        switch (color)
        {
        case COLOR::RED:
            r = 255;
            g = 0;
            b = 0;
            break;
        default:
            break;
        }
        return *this;
    }
};

