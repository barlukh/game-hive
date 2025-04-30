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
    
    Rectangle hiveRect = {80, 464, (float)hive.width, (float)hive.height}; 
    Rectangle beeRect = {1000, 600, (float)bee[0].width, (float)bee[0].height}; 

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_UP))
			beeRect.y -= beeSpeed;
		if (IsKeyDown(KEY_DOWN))
			beeRect.y += beeSpeed;
		if (IsKeyDown(KEY_LEFT))
			beeRect.x -= beeSpeed;
		if (IsKeyDown(KEY_RIGHT))
			beeRect.x += beeSpeed;
		
		timeElapsed += GetFrameTime();
        if (timeElapsed >= frameTime) {
            currentFrame = (currentFrame + 1) % 4;
            timeElapsed = 0.0f;
        }

        BeginDrawing();
            ClearBackground(WHITE);
            
            DrawTexture(background, 0, 0, WHITE);
            DrawTexture(hive, (int)hiveRect.x, (int)hiveRect.y, WHITE);
            DrawTexture(bee[currentFrame], (int)beeRect.x, (int)beeRect.y, WHITE);

        EndDrawing();
    }
    
    UnloadTexture(background);
    UnloadTexture(hive);
    for (int i = 0; i < 4; i++) {
        UnloadTexture(bee[i]);
    }
    CloseWindow();

    return (0);
}
