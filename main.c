#include <raylib.h>

int main(void)
{
    SetTraceLogLevel(LOG_NONE);

    const int screenWidth = 2560;
    const int screenHeight = 1440;
    const char *screenTitle = "Defenders of the Hive!";

    InitWindow(screenWidth, screenHeight, screenTitle);
    // SetWindowState(FLAG_FULLSCREEN_MODE);

    SetTargetFPS(60);

    float beeSpeed = 4.0f;

    int currentFrame = 0;
    float frameTime = 0.2f;
    float timeElapsed = 0.0f;

    Texture2D background = LoadTexture("graphics/background.png");
    Texture2D hive = LoadTexture("graphics/hive.png");
    Texture2D bee[4] = {
        LoadTexture("graphics/bee1.png"),
        LoadTexture("graphics/bee2.png"),
        LoadTexture("graphics/bee3.png"),
        LoadTexture("graphics/bee4.png")
    };

    Vector2 hivePos = {80.0f, 464.0f};
    Vector2 beePos = {1000.0f, 600.0f};

    Rectangle hiveRect = {hivePos.x, hivePos.y, (float)hive.width, (float)hive.height};
    Rectangle beeRect = {beePos.x, beePos.y, (float)bee[0].width, (float)bee[0].height};

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_UP))
            beePos.y -= beeSpeed;
        if (IsKeyDown(KEY_DOWN))
            beePos.y += beeSpeed;
        if (IsKeyDown(KEY_LEFT))
            beePos.x -= beeSpeed;
        if (IsKeyDown(KEY_RIGHT))
            beePos.x += beeSpeed;

        beeRect.x = beePos.x;
        beeRect.y = beePos.y;

        timeElapsed += GetFrameTime();
        if (timeElapsed >= frameTime) {
            currentFrame = (currentFrame + 1) % 4;
            timeElapsed = 0.0f;
        }

        BeginDrawing();
            ClearBackground(WHITE);
            
            DrawTexture(background, 0, 0, WHITE);
            DrawTexture(hive, (int)hivePos.x, (int)hivePos.y, WHITE);
            DrawTexture(bee[currentFrame], (int)beePos.x, (int)beePos.y, WHITE);

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(hive);
    for (int i = 0; i < 4; i++) {
        UnloadTexture(bee[i]);
    }
    CloseWindow();

    return 0;
}
