#include <raylib.h>

int main(void)
{
	SetTraceLogLevel(LOG_NONE);

	const int screenWidth = 2560;
	const int screenHeight = 1440;
	const char *screenTitle = "Bees!";

	InitWindow(screenWidth, screenHeight, screenTitle);

	SetTargetFPS(60);

	
	while (!WindowShouldClose())
	{
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Hello", 190, 200, 20, LIGHTGRAY);
		
		EndDrawing();
	}

	CloseWindow();

	return (0);
}