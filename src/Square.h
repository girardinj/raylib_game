#pragma once

#include <raylib.h>

class Square {
    public:
        Square(double length, Vector2 position, Vector2 direction, Color color);
        void draw();
    private:
        double length;
        int id;
        Vector2 position;
        Vector2 direction;
        Color color;
        static int COUNTER;
};
