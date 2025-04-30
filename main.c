#include <raylib.h>

typedef enum GameScreen { INTRO = 0, GAMEPLAY } GameScreen;

int main(void)
{
    SetTraceLogLevel(LOG_NONE);

    const int screenWidth = 2560;
    const int screenHeight = 1440;
    const char *screenTitle = "Guardians of the Hive!";

    InitWindow(screenWidth, screenHeight, screenTitle);

    GameScreen currentScreen = INTRO;

    SetTargetFPS(60);

    float beeSpeed = 8.0f;

    int currentFrame = 0;
    float frameTime = 0.2f;
    float timeElapsed = 0.0f;

	Texture2D intro = LoadTexture("graphics/intro.png");
    Texture2D background = LoadTexture("graphics/background.png");
    Texture2D hive = LoadTexture("graphics/hive.png");
    Texture2D bee[4] = {
        LoadTexture("graphics/bee1.png"),
        LoadTexture("graphics/bee2.png"),
        LoadTexture("graphics/bee3.png"),
        LoadTexture("graphics/bee4.png")
    };

    Vector2 hivePos = { 80.0f, 464.0f };
    Vector2 beePos = { 1000.0f, 600.0f };

    Rectangle hiveRect = { hivePos.x, hivePos.y, (float)hive.width, (float)hive.height };
    Rectangle beeRect = { beePos.x, beePos.y, (float)bee[0].width, (float)bee[0].height };

    while (!WindowShouldClose())
    {
        switch (currentScreen)
        {
            case INTRO:
            {
                BeginDrawing();
                    ClearBackground(WHITE);
					DrawTexture(intro, 0, 0, WHITE);
                    DrawText("Press ENTER to start!", screenWidth / 2 - 240, 1300, 40, PINK); // make it centered
                EndDrawing();

                if (IsKeyPressed(KEY_ENTER))
                    currentScreen = GAMEPLAY;
            } break;

            case GAMEPLAY:
            {
                // Movement controls
                if (IsKeyDown(KEY_UP)) beePos.y -= beeSpeed;
                if (IsKeyDown(KEY_DOWN)) beePos.y += beeSpeed;
                if (IsKeyDown(KEY_LEFT)) beePos.x -= beeSpeed;
                if (IsKeyDown(KEY_RIGHT)) beePos.x += beeSpeed;

                // Boundary checks
                if (beePos.x < 0) beePos.x = 0;
                if (beePos.x + bee[0].width > screenWidth) beePos.x = screenWidth - bee[0].width;
                if (beePos.y < 0) beePos.y = 0;
                if (beePos.y + bee[0].height > screenHeight) beePos.y = screenHeight - bee[0].height;

                // Update bee animation
                timeElapsed += GetFrameTime();
                if (timeElapsed >= frameTime) {
                    currentFrame = (currentFrame + 1) % 4;
                    timeElapsed = 0.0f;
                }

                // Update bee rectangle
                beeRect.x = beePos.x;
                beeRect.y = beePos.y;

                BeginDrawing();
                    ClearBackground(WHITE);

                    // Draw the game elements
                    DrawTexture(background, 0, 0, WHITE);
                    DrawTextureV(hive, hivePos, WHITE);
                    DrawTextureEx(bee[(currentFrame + 1) % 4], (Vector2){ hivePos.x + 30, hivePos.y + 150 }, 0, 0.60, WHITE);
                    DrawTextureEx(bee[(currentFrame + 2) % 4], (Vector2){ hivePos.x + 450, hivePos.y + 80 }, 0, 0.75, WHITE);
                    DrawTextureEx(bee[(currentFrame + 3) % 4], (Vector2){ hivePos.x + 270, hivePos.y + 380 }, 0, 0.50, WHITE);
                    DrawTextureEx(bee[(currentFrame + 3) % 4], (Vector2){ hivePos.x + 270, hivePos.y + 20 }, 0, 0.50, WHITE);
                    DrawTextureEx(bee[currentFrame], (Vector2){ hivePos.x + 210, hivePos.y + 320 }, 0, 0.75, WHITE);
                    DrawTextureV(bee[currentFrame], beePos, WHITE);
                EndDrawing();
            } break;
			default: break;
        }
    }

    // Clean up resources after exiting the game loop
    UnloadTexture(background);
    UnloadTexture(hive);
    for (int i = 0; i < 4; i++) {
        UnloadTexture(bee[i]);
    }

    CloseWindow();

    return 0;
}