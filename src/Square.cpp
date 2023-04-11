#include "Square.h"
#include <string>

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
    DrawText(std::to_string(this->id).c_str(), this->position.x, this->position.y, this->length, BLACK);
}

void Square::move(int rightBorder, int bottomBorder) {
    
    if (this->position.x + this->length >= rightBorder - this->direction.x ||
      this->position.x + this->direction.x <= 0)
        this->direction.x *= -1;
    
    if (this->position.y  + this->length >= bottomBorder - this->direction.y ||
      this->position.y + this->direction.y <= 0)
        this->direction.y *= -1;

    this->position.x += this->direction.x;
    this->position.y += this->direction.y;
}
