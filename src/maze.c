#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

void generate_maze(char maze[MAX_ROWS][MAX_COLS], int rows, int cols) {
    // Seed random generator
    srand((unsigned int)time(NULL));

    // Fill the maze with walls
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = '#';
        }
    }

    // Create paths in the maze
    for (int i = 1; i < rows - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {
            maze[i][j] = (rand() % 4 == 0) ? '#' : ' '; // Randomly place walls
        }
    }

    // Place player start position
    maze[1][1] = 'P';

    // Place maze exit
    maze[rows - 2][cols - 2] = 'E';
}

void display_maze(char maze[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 'P')
                printf(COLOR_PLAYER "P" COLOR_RESET);
            else if (maze[i][j] == 'M')
                printf(COLOR_ENEMY "M" COLOR_RESET);
            else if (maze[i][j] == 'E')
                printf(COLOR_EXIT "E" COLOR_RESET);
            else
                printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(char maze[MAX_ROWS][MAX_COLS], int rows, int cols, Config *config) {
    srand((unsigned int)time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = config->wall_symbol; // Use wall symbol from config
        }
    }

    for (int i = 1; i < rows - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {
            maze[i][j] = (rand() % 4 == 0) ? config->wall_symbol : config->path_symbol;
        }
    }

    // Player start position
    maze[1][1] = config->player_symbol;

    // Exit position
    maze[rows - 2][cols - 2] = config->exit_symbol;
}