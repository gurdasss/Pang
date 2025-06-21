#include "Ball.h"
#include "Player.h"
#include <raylib.h>

int main()
{
    constexpr int screenW{800};
    constexpr int screenH{450};

    InitWindow(screenW, screenH, "Pang");

    constexpr int targetFPS{60};
    SetTargetFPS(targetFPS);

    Ball ball{Vector2{screenW / 2.0f, screenH / 2.0f}};

    Player player{Vector2{screenW / 2.0f, screenH - 10.0f}};

    while (!WindowShouldClose())
    {
        constexpr float delta{1.0f / targetFPS};
        constexpr float playerMoveSpeed{300};

        if (IsKeyDown(KEY_LEFT))
            player.updateX(-playerMoveSpeed * delta);
        else if (IsKeyDown(KEY_RIGHT))
            player.updateX(playerMoveSpeed * delta);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        ball.draw(delta);
        player.draw();

        DrawFPS(0, 0);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}