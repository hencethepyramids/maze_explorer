#include <stdio.h>
#include "utils.h"
#include "maze.h"
#include "player.h"
#include "enemy.h"
#include "audio.h"

int main() {
    // Load configuration
    Config config;
    if (!load_config(&config, "assets/default_config.txt")) {
        fprintf(stderr, "Error loading configuration file.\n");
        return 1;
    }

    // Initialize audio
    if (!init_audio()) {
        fprintf(stderr, "Error initializing audio system.\n");
        return 1;
    }

    play_music("assets/background_music.wav");

    // Initialize maze, player, and enemy
    char maze[MAX_ROWS][MAX_COLS];
    Player player;
    Enemy enemy;

    generate_maze(maze, config.maze_rows, config.maze_cols, &config);
    initialize_player(&player);
    initialize_enemy(&enemy, maze, config.maze_rows, config.maze_cols);

    // Display introduction
    printf("Maze Explorer!\n");
    printf("Controls: W (up), A (left), S (down), D (right). Press Q to quit.\n\n");

    // Game loop
    int game_over = 0;
    char input;

    while (!game_over) {
        // Display the maze and score
        display_maze(maze, config.maze_rows, config.maze_cols);
        printf("\nScore: %d\n", player.score);
        printf("Enter your move: ");
        scanf(" %c", &input);

        // Handle quitting
        if (input == 'q' || input == 'Q') {
            printf("Thanks for playing!\n");
            play_sound("assets/game_over.wav");
            break;
        }

        // Move the player
        if (move_player(&player, maze, input)) {
            update_score(&player, 100); // Bonus for reaching the exit
            printf("Congratulations! You found the exit!\n");
            play_sound("assets/victory.wav");
            break;
        } else {
            update_score(&player, 10); // Points for valid moves
            play_sound("assets/move.wav");
        }

        // Move the enemy
        move_enemy(&enemy, &player, maze);

        // Check for collision
        if (enemy.x == player.x && enemy.y == player.y) {
            printf("Game Over! You were caught by the enemy!\n");
            game_over = 1;
            update_score(&player, -50); // Deduct points for being caught
            play_sound("assets/game_over.wav");
        }
    }

    // Final score
    printf("\nFinal Score: %d\n", player.score);

    // Cleanup audio
    cleanup_audio();

    return 0;
}