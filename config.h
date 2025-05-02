#ifndef CONFIG_H
#define CONFIG_H

//----------------------------------------------------------------------------------
// Library Headers
//----------------------------------------------------------------------------------
#include <raylib.h>

//----------------------------------------------------------------------------------
// Macro Definitions
//----------------------------------------------------------------------------------
#define SCREEN_WIDTH 2560
#define SCREEN_HEIGHT 1440
#define GAME_TITLE "Guardians of the Hive!"
#define SCREEN_FPS 60
#define BEE_SPEED 10.0f;

//----------------------------------------------------------------------------------
// Type Definitions
//----------------------------------------------------------------------------------
// Enumeration for different states of the game
typedef enum GameState {
	INTRO = 0,
	GAMEPLAY
} GameState;

// Frame tracking for animations
typedef struct FrameConfig {
	int frame;			// Current frame displayed
	float threshold;	// Threshold value for the next frame
	float elapsed;		// Time elapsed
} FrameConfig;

//----------------------------------------------------------------------------------
// Function Prototypes
//----------------------------------------------------------------------------------
void gamestate_intro(GameState *currentState, Texture2D backgroundIntro);

#endif
