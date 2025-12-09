#include "raylib.h"
#include "raymath.h"

int main(void)
{
    InitWindow(800, 600, "Smooth Top-Down 2D Camera Follow");

    Vector2 playerPos = {400, 300};
    float playerSpeed = 200.0f;

    Camera2D camera = {0};
    camera.target = playerPos;
    camera.offset = {400, 300}; // центр екрана
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        ClearBackground(GREEN);
        // --- Керування гравцем ---
        if (IsKeyDown(KEY_W))
            playerPos.y -= playerSpeed * dt;
        if (IsKeyDown(KEY_S))
            playerPos.y += playerSpeed * dt;
        if (IsKeyDown(KEY_A))
            playerPos.x -= playerSpeed * dt;
        if (IsKeyDown(KEY_D))
            playerPos.x += playerSpeed * dt;

        // --- Плавне слідкування ---
        float smoothSpeed = 5.0f;
        camera.target = Vector2Lerp(camera.target, playerPos, smoothSpeed * dt);
        float mapWidth = 1000;
        float mapHeight = 1000;

        playerPos.x = Clamp(playerPos.x, -1000, mapWidth);
        playerPos.y = Clamp(playerPos.y, -1000, mapHeight);
        // --- Малювання ---
        BeginDrawing();

        BeginMode2D(camera);
        // Сітка для орієнтації
        for (int x = -1000; x <= 1000; x += 50)
            DrawLine(x, -1000, x, 1000, BLACK);
        for (int y = -1000; y <= 1000; y += 50)
            DrawLine(-1000, y, 1000, y, BLACK);

        // Гравець (синій квадрат)
        DrawRectangleV(Vector2Subtract(playerPos, {10, 10}), {20, 20}, BLUE);
        EndMode2D();

        DrawText("WASD to move — camera follows smoothly", 10, 10, 20, DARKGRAY);
        DrawText("Press SPACE — nothing breaks now :)", 10, 40, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
