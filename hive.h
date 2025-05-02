#ifndef HIVE_H
#define HIVE_H

#include <raylib.h>

// Screen configuration values
typedef struct ScreenConfig {
	const int width;	// Screen width
	const int height;	// Screen height
	const int fps;		// Target FPS
} ScreenConfig;

// Enumeration for different states of the game
typedef enum GameState {
	INTRO = 0,
	GAMEPLAY
} GameState;

// Frame tracking for animations
typedef struct FrameConfig {
	int current;		// Used for correct animation frame tracking
	float threshold;	// Threshold value for the next animation frame
	float elapsed;		// Time elapsed
} FrameConfig;

#endif
