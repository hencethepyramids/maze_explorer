#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include "maze.h"
#include "player.h"

void initialize_enemy(Enemy *enemy, char maze[MAX_ROWS][MAX_COLS], int rows, int cols) {
    // Randomly place the enemy in an open space
    int x, y;
    do {
        x = rand() % rows;
        y = rand() % cols;
    } while (maze[x][y] != ' '); // Ensure the spot is open

    enemy->x = x;
    enemy->y = y;
    maze[x][y] = 'M'; // 'M' for monster
}

void move_enemy(Enemy *enemy, Player *player, char maze[MAX_ROWS][MAX_COLS]) {
    int new_x = enemy->x;
    int new_y = enemy->y;
    int moved = 0;

    // Attempt to move toward the player
    if (player->x > enemy->x && maze[enemy->x + 1][enemy->y] == ' ') {
        new_x++;
        moved = 1;
    } else if (player->x < enemy->x && maze[enemy->x - 1][enemy->y] == ' ') {
        new_x--;
        moved = 1;
    }
    if (!moved && player->y > enemy->y && maze[enemy->x][enemy->y + 1] == ' ') {
        new_y++;
        moved = 1;
    } else if (!moved && player->y < enemy->y && maze[enemy->x][enemy->y - 1] == ' ') {
        new_y--;
        moved = 1;
    }

    // If blocked, move randomly
    if (!moved) {
        int random_dir = rand() % 4;
        switch (random_dir) {
            case 0: if (maze[enemy->x + 1][enemy->y] == ' ') new_x++; break;
            case 1: if (maze[enemy->x - 1][enemy->y] == ' ') new_x--; break;
            case 2: if (maze[enemy->x][enemy->y + 1] == ' ') new_y++; break;
            case 3: if (maze[enemy->x][enemy->y - 1] == ' ') new_y--; break;
        }
    }

    // Update enemy position
    maze[enemy->x][enemy->y] = ' '; // Clear old position
    enemy->x = new_x;
    enemy->y = new_y;
    maze[enemy->x][enemy->y] = 'M'; // Mark new position
}