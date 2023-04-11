#include "Button.h"
#include <iostream>

Button::Button(Vector2 position, Vector2 size, Color color) {
    this->position = position;
    this->size = size;
    this->color = color;
    this->isPressed = false;

    this->pressedColor = color;
    int substractColorValue = 150;

    auto f = [](unsigned char &color, int substractValue) {
        if (color - substractValue < 0)
            color = 0;
        else
            color = color - substractValue;
    };
    f(this->pressedColor.r, substractColorValue);
    f(this->pressedColor.g, substractColorValue);
    f(this->pressedColor.b, substractColorValue);
}

void Button::draw() {

    if (IsMouseButtonPressed(0) && isMouseInside()) {
        isPressed = true;
    }
    else if (!IsMouseButtonDown(0)) {
        isPressed = false;
    }

    Color colorToDraw = isPressed ? this->pressedColor : this->color;

    // std::cout << (int)colorToDraw.r << " " << (int)colorToDraw.g << " " << (int)colorToDraw.b << std::endl;
    DrawRectangleV(this->position, this->size, colorToDraw);
    DrawText("Press me", this->position.x, this->position.y, this->size.x, BLACK);

    if (IsMouseButtonPressed(0) && isMouseInside()) {
        callback();
    }
}

// void (*callback)(void) only works with non capture group lambdas
void Button::onClick(std::function<void(void)> callback) {
    this->callback = callback;
}

bool Button::isMouseInside() {
    Vector2 mousePosition = GetMousePosition();
    return mousePosition.x >= this->position.x && mousePosition.x <= this->size.x &&
        mousePosition.y >= this->position.y && mousePosition.y <= this->size.y;
}

