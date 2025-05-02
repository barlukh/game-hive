#include "config.h"

int main(void)
{
	SetTraceLogLevel(LOG_NONE);

	// Initial screen and game configuration
	GameState currentState = INTRO;
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
	SetTargetFPS(SCREEN_FPS);
	// SetWindowState(FLAG_FULLSCREEN_MODE);

	// Animation and frame settings
	FrameConfig time = { 0, 0.2f, 0.0f };

	// Initial textures, vectors, and rectangles
	Texture2D backgroundIntro = LoadTexture("graphics/background_intro.png");
	Texture2D backgroundGameplay = LoadTexture("graphics/background_gameplay.png");
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
		switch (currentState)
		{
			case INTRO:
				intro(&currentState, backgroundIntro);
			break;

			case GAMEPLAY:
			{
				// Movement controls
				if (IsKeyDown(KEY_UP)) beePos.y -= BEE_SPEED;
				if (IsKeyDown(KEY_DOWN)) beePos.y += BEE_SPEED;
				if (IsKeyDown(KEY_LEFT)) beePos.x -= BEE_SPEED;
				if (IsKeyDown(KEY_RIGHT)) beePos.x += BEE_SPEED;

				// Boundary checks
				if (beePos.x < 0) beePos.x = 0;
				if (beePos.x + bee[0].width > SCREEN_WIDTH) beePos.x = SCREEN_HEIGHT - bee[0].width;
				if (beePos.y < 0) beePos.y = 0;
				if (beePos.y + bee[0].height > SCREEN_WIDTH) beePos.y = SCREEN_HEIGHT - bee[0].height;

				// Update bee animation
				time.elapsed += GetFrameTime();
				if (time.elapsed >= time.threshold) {
					time.frame = (time.frame + 1) % 4;
					time.elapsed = 0.0f;
				}

				// Update bee rectangle
				beeRect.x = beePos.x;
				beeRect.y = beePos.y;

				BeginDrawing();
					ClearBackground(WHITE);

					DrawTexture(backgroundGameplay, 0, 0, WHITE);
					DrawTextureV(hive, hivePos, WHITE);
					DrawTextureEx(bee[(time.frame + 1) % 4], (Vector2){ hivePos.x + 30, hivePos.y + 150 }, 0, 0.60, WHITE);
					DrawTextureEx(bee[(time.frame + 2) % 4], (Vector2){ hivePos.x + 450, hivePos.y + 80 }, 0, 0.75, WHITE);
					DrawTextureEx(bee[(time.frame + 3) % 4], (Vector2){ hivePos.x + 270, hivePos.y + 380 }, 0, 0.50, WHITE);
					DrawTextureEx(bee[(time.frame + 3) % 4], (Vector2){ hivePos.x + 270, hivePos.y + 20 }, 0, 0.50, WHITE);
					DrawTextureEx(bee[time.frame], (Vector2){ hivePos.x + 210, hivePos.y + 320 }, 0, 0.75, WHITE);
					DrawTextureV(bee[time.frame], beePos, WHITE);
				
				EndDrawing();
			} break;
			default: break;
		}
	}

	// Clean up resources after exiting the game loop
	UnloadTexture(backgroundIntro);
	UnloadTexture(backgroundGameplay);
	UnloadTexture(hive);
	for (int i = 0; i < 4; i++) {
		UnloadTexture(bee[i]);
	}

	CloseWindow();

	return 0;
}