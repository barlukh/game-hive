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

	while (!WindowShouldClose())
	{
        timeElapsed += GetFrameTime();
        if (timeElapsed >= frameTime) {
            currentFrame = (currentFrame + 1) % 4;
            timeElapsed = 0.0f;
        }

		BeginDrawing();
			DrawTexture(background, 0, 0, WHITE);
			DrawTexture(hive, 80, 464, WHITE);
			DrawTexture(bee[currentFrame], 1000, 600, WHITE);
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