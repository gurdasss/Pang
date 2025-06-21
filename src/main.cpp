#include "Ball.h"
#include <raylib.h>

int main()
{
    constexpr int screenW{800};
    constexpr int screenH{450};

    InitWindow(screenW, screenH, "Pang");

    constexpr int targetFPS{60};
    SetTargetFPS(targetFPS);

    Ball ball{};
    ball.setInitialPosition(Vector2{screenW / 2.0f, screenH / 2.0f});

    while (!WindowShouldClose())
    {
        constexpr float delta{1.0f / targetFPS};

        BeginDrawing();
        ClearBackground(RAYWHITE);

        ball.draw(delta);

        DrawFPS(0, 0);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}