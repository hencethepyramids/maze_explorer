#ifndef MAZE_H
#define MAZE_H

#include <time.h>

// Define the maze size limits
#define MAX_ROWS 50
#define MAX_COLS 50

// Color definitions
#define COLOR_RESET "\033[0m"
#define COLOR_PLAYER "\033[32m" // Green
#define COLOR_ENEMY "\033[31m" // Red
#define COLOR_EXIT "\033[33m"  // Yellow

// Function prototypes
void generate_maze(char maze[MAX_ROWS][MAX_COLS], int rows, int cols, Config *config);
void display_maze(char maze[MAX_ROWS][MAX_COLS], int rows, int cols);

#endif