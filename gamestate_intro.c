#include "config.h"

void gamestate_intro(GameState *currentState, Texture2D backgroundIntro)
{
	BeginDrawing();

		ClearBackground(WHITE);
		DrawTexture(backgroundIntro, 0, 0, WHITE);
		
		int textWidth = MeasureText("Press ENTER to start!", 50);
		DrawText("Press ENTER to start!", SCREEN_WIDTH / 2 - textWidth / 2, 1300, 50, ORANGE);

	EndDrawing();

	if (IsKeyPressed(KEY_ENTER))
		*currentState = GAMEPLAY;
}