#pragma once

#include <raylib.h>

class Square {
    public:
        Square(double length, Vector2 position, Vector2 direction, Color color);
        void draw();
        void move(int rightBorder, int bottomBorder);
    private:
        Vector2 size;
        int id;
        Vector2 position;
        Vector2 direction;
        Color color;
        static int COUNTER;
};
