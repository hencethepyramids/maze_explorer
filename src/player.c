// player.c
#include <stdio.h>
#include "player.h"
#include "maze.h"
#include "utils.h"

void initialize_player(Player *player) {
    player->x = 0;   // Starting position (row)
    player->y = 0;   // Starting position (column)
    player->score = 0; // Initialize score
}

void update_score(Player *player, int points) {
    player->score += points;
}

int move_player(Player *player, char maze[MAX_ROWS][MAX_COLS], char direction) {
    int new_x = player->x;
    int new_y = player->y;

    // Determine the new position based on the direction
    switch (direction) {
        case 'w': new_x -= 1; break; // Up
        case 's': new_x += 1; break; // Down
        case 'a': new_y -= 1; break; // Left
        case 'd': new_y += 1; break; // Right
        default: 
            printf("Invalid move. Use W/A/S/D to navigate.\n");
            return 0;
    }

    // Check if the move is valid (not hitting walls or out of bounds)
    if (maze[new_x][new_y] == ' ' || maze[new_x][new_y] == 'E') {
        // Update player position
        maze[player->x][player->y] = ' '; // Clear the old position
        player->x = new_x;
        player->y = new_y;
        maze[player->x][player->y] = 'P'; // Update to new position
        return (maze[new_x][new_y] == 'E'); // Return 1 if the player reached the exit
    }

    printf("You can't move there! It's a wall.\n");
    return 0;
}