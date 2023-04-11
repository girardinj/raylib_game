#include <iostream>
#include <string>
#include <raylib.h>
#include <vector>
#include <time.h>
#include <random>

#include "colors.h"
#include "square.h"
#include "Button.h"

// TODO: Sometimes a button is not there, outside of  the box ?
Square* generateSquare(int minSize, int maxSize, int windowWidth, int windowHeight, std::mt19937 &generator) {

    
    // between minSize and maxSize
    std::uniform_int_distribution<int> distSize(minSize, maxSize);

    int size = distSize(generator);
    
    
    // position is whole grid
    std::uniform_int_distribution<int> distPositionX(0, windowWidth - size);
    std::uniform_int_distribution<int> distPositionY(0, windowHeight - size);

    int posX = distPositionX(generator);
    int posY = distPositionY(generator);
    Vector2 position = {(float)posX, (float)posY};


    // direction is [1;3] and positive or negative
    std::uniform_int_distribution<int> distDirection(0, 5);
    std::uniform_int_distribution<int> distSign(1, 2);
    
    int dirX = distDirection(generator) * (distSign(generator) == 1 ? 1 : -1);
    int dirY = distDirection(generator) * (distSign(generator) == 1 ? 1 : -1);
    Vector2 direction = {(float)dirX, (float)dirY};

    // std::cout << dirX << " " << dirY << std::endl;
    // choose a random color from the list
    std::uniform_int_distribution<int> distColor(0, sizeof(colors)/sizeof(Color));
    Color color = colors[distColor(generator)];

    Square* square = new Square(size, position, direction, color);
    return square;
}

int main(int argc, char **argv) {
        
    std::random_device device;
    std::mt19937 generator(time(0));

    int windowWidth = 800;
    int windowHeight = 600;

    InitWindow(windowWidth, windowHeight, "Fenetre");

    SetWindowState(FLAG_VSYNC_HINT);
    

    std::vector<Square*> squaresList;


    Button btn({0, 0}, {100, 80}, RED);
    btn.onClick([&]() {
            squaresList.push_back(generateSquare(50, 200, windowWidth, windowHeight, generator));
        });
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        for (auto p : squaresList) {
            p->draw();
            p->move(windowWidth, windowHeight);
        }
        btn.draw();

        EndDrawing();
    }


    // delete all squares
    for (Square* square : squaresList)
        delete square;

    CloseWindow();

    return 0;
}