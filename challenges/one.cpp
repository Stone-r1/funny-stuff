#include <iostream>
#include <ctime>
#include <cstdlib>
#include "raylib.h"


const int width = 600, height = 600, stars = 700;

class Star {
    double x, y, z;

public:
    Star()
    {
        reset();
    }

    void reset()
    {
        // just a random range from which stars start to appear.
        x = (rand() % 7001 - 5000);
        y = (rand() % 7001 - 5000);
        z = (rand() % 1001 + 1);
    }

    void update()
    {
        // speed of stars.
        z -= 5;
        if (z <= 0.0) reset();
    }

    void draw()
    {
        // less number more density.
        double offsetX = (50.0 * x / z) + width / 2.0;
        double offsetY = (50.0 * y / z) + height / 2.0;
        // larger number makes more stars appear at once, thus more dense.
        double scaleZ = 1.0 - (z / 500.0);

        // radius of a star.
        // double r = ((rand() / (double)RAND_MAX) * (10.0 - 3.0) + 3.0) * scaleZ;
        // this would work if updates were saved somewhere, but at this point it just redraws radiuses with arbitrary numbers.

        double r = 5.0 * scaleZ;
        DrawCircle(offsetX, offsetY, r, WHITE);
    }
};


int main()
{
    srand(time(nullptr));
    
    InitWindow(width, height, "bonk");
    SetTargetFPS(60);

    Star star[stars];

    while (!WindowShouldClose())
    {
        // update
        for (int i = 0; i < stars; i++)
        {
            star[i].update();
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < stars; i++)
        {
            star[i].draw();
        }

        EndDrawing();
    }

    CloseWindow();
}
