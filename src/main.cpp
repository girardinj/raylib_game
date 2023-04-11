#include <iostream>
#include <string>
#include <raylib.h>
#include "square.h"
#include <vector>
#include <time.h>
#include "colors.h"



Square* generateSquare(int minSize, int maxSize, int windowWidth, int windowHeight) {

    int size = minSize + std::rand() % (maxSize + 1 - minSize);

    int posX = std::rand() % (windowWidth - size);
    int posY = std::rand() % (windowHeight - size);
    Vector2 position = {(float)posX, (float)posY};

    int dirX = std::rand() % (windowWidth - size);
    int dirY = std::rand() % (windowHeight - size);
    Vector2 direction = {(float)dirX, (float)dirY};

    Color color = colors[std::rand() % sizeof(colors)/sizeof(Color)];

    Square* square = new Square(size, position, color);
    return square;
}

int main(int argc, char **argv) {
    
    std::srand(time(NULL));
    
    int windowWidth = 800;
    int windowHeight = 600;

    InitWindow(windowWidth, windowHeight, "Fenetre");

    SetWindowState(FLAG_VSYNC_HINT);
    

    std::vector<Square*> squaresList;

    squaresList.push_back(generateSquare(50, 200, windowWidth, windowHeight));
    squaresList.push_back(generateSquare(50, 200, windowWidth, windowHeight));
    squaresList.push_back(generateSquare(50, 200, windowWidth, windowHeight));
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        for (auto p : squaresList) {
            p->draw();
        }
        EndDrawing();
    }


    // delete all squares
    for (Square* square : squaresList)
        delete square;

    CloseWindow();

    return 0;
}