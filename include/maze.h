#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <time.h>
#include "utils.h" // Assuming Config is defined here or include its definition

// Define the maze size limits
#define MAX_ROWS 50
#define MAX_COLS 50

// Color definitions for terminal output
#define COLOR_RESET "\033[0m"
#define COLOR_PLAYER "\033[32m" // Green
#define COLOR_ENEMY "\033[31m" // Red
#define COLOR_EXIT "\033[33m"  // Yellow
#define COLOR_WALL "\033[34m"  // Blue
#define COLOR_PATH "\033[37m"  // White

// Function prototypes
void generate_maze(char maze[MAX_ROWS][MAX_COLS], int rows, int cols, Config *config);
void display_maze(char maze[MAX_ROWS][MAX_COLS], int rows, int cols);
void load_maze(char maze[MAX_ROWS][MAX_COLS], const char *filename, int *rows, int *cols);

#endif // MAZE_H