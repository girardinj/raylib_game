#pragma once

#include <raylib.h>
#include <functional>

class Button {
    public:
        Button(Vector2 position, Vector2 size, Color color);
        void draw();
        void onClick(std::function<void(void)> callback);

    private:
        bool isMouseInside();
        bool isPressed;

        Color color;
        Vector2 size;
        Vector2 position;

        std::function<void(void)> callback;

        Color pressedColor;
};
