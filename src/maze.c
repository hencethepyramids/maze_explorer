#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "maze.h"

// Function to generate a random maze
void generate_maze(char maze[MAX_ROWS][MAX_COLS], int rows, int cols, Config *config) {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Fill the maze with walls
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = config->wall_symbol; // Use wall symbol from configuration
        }
    }

    // Create paths in the maze
    for (int i = 1; i < rows - 1; i++) {
        for (int j = 1; j < cols - 1; j++) {
            maze[i][j] = (rand() % 4 == 0) ? config->wall_symbol : config->path_symbol;
        }
    }

    // Set player start position
    maze[1][1] = config->player_symbol;

    // Set exit position
    maze[rows - 2][cols - 2] = config->exit_symbol;
}

// Function to display the maze with colors
void display_maze(char maze[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            switch (maze[i][j]) {
                case 'P': printf(COLOR_PLAYER "P" COLOR_RESET); break;
                case 'E': printf(COLOR_EXIT "E" COLOR_RESET); break;
                case '#': printf(COLOR_WALL "#" COLOR_RESET); break;
                case ' ': printf(COLOR_PATH " " COLOR_RESET); break;
                default:  printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to load a maze from a file
void load_maze(char maze[MAX_ROWS][MAX_COLS], const char *file, int *rows, int *cols) {
    FILE *f = fopen(file, "r");
    if (!f) {
        fprintf(stderr, "Error: Could not load maze file: %s\n", file);
        exit(1);
    }

    int row = 0;
    int col = 0;
    char line[MAX_COLS + 2]; // +2 for newline and null terminator

    while (fgets(line, sizeof(line), f)) {
        col = 0;
        for (int i = 0; line[i] != '\n' && line[i] != '\0'; i++) {
            maze[row][col++] = line[i];
        }
        row++;
    }

    *rows = row;
    *cols = col;

    fclose(f);
}