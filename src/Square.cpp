#include "Square.h"

int Square::COUNTER = 0;

Square::Square(double length, Vector2 position, Vector2 direction, Color color) {
    this->id = Square::COUNTER++;
    this->length = length;
    this->position = position;
    this->direction = direction;
    this->color = color;
}

void Square::draw() {
    DrawRectangle(this->position.x, this->position.y, this->length, this->length, this->color);
}
