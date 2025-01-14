#ifndef PLAYER_H
#define PLAYER_H

#include "maze.h"

// Define the player structure
typedef struct {
    int x, y; // Player's current position
} Player;

// Function prototypes
void initialize_player(Player *player);
int move_player(Player *player, char maze[MAX_ROWS][MAX_COLS], char direction);

#endif