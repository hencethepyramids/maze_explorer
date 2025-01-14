#ifndef ENEMY_H
#define ENEMY_H

#include "maze.h"
#include "player.h"

// Define the enemy structure
typedef struct {
    int x, y; // Enemy's current position
} Enemy;

// Function prototypes
void initialize_enemy(Enemy *enemy, char maze[MAX_ROWS][MAX_COLS], int rows, int cols);
void move_enemy(Enemy *enemy, Player *player, char maze[MAX_ROWS][MAX_COLS]);

#endif