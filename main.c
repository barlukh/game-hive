#include <raylib.h>

int main(void)
{
	SetTraceLogLevel(LOG_NONE);

	const int screenWidth = 2560;
	const int screenHeight = 1440;
	const char *screenTitle = "Defenders of the Hive";

	InitWindow(screenWidth, screenHeight, screenTitle);

	SetTargetFPS(60);

	Texture2D background = LoadTexture("graphics/background.png");
	Texture2D hive = LoadTexture("graphics/hive.png");
	Texture2D bee[4] = {
        LoadTexture("graphics/bee1.png"),
        LoadTexture("graphics/bee2.png"),
        LoadTexture("graphics/bee3.png"),
        LoadTexture("graphics/bee4.png")
	};
	
	int currentFrame = 0;
    float frameTime = 0.2f;
    float timeElapsed = 0.0f;

	while (!WindowShouldClose())
	{
		// Update animation frame
        timeElapsed += GetFrameTime();
        if (timeElapsed >= frameTime) {
            currentFrame = (currentFrame + 1) % 4; // Loop back to the first image
            timeElapsed = 0.0f;
        }

		BeginDrawing();
			DrawTexture(background, 0, 0, WHITE);
			DrawTexture(hive, 80, 464, WHITE);
			DrawTexture(bee[currentFrame], screenWidth/2 - bee[currentFrame].width/2,
				screenHeight/2 - bee[currentFrame].height/2, WHITE);
		
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