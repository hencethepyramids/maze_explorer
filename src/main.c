#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "maze.h"
#include "player.h"
#include "enemy.h"
#include "audio.h"

// Progress tracking
bool progress_exists = false;
char last_completed_maze[256] = "assets/mazes/maze_easy.txt"; // Default to first maze

void display_menu() {
    printf("\n=== Maze Explorer ===\n");
    printf("1. Start\n");
    if (progress_exists) {
        printf("2. Continue\n");
    } else {
        printf("2. Continue (Unavailable)\n");
    }
    printf("3. Load\n");
    printf("4. Level Selector\n");
    printf("5. Settings\n");
    printf("=====================\n");
    printf("Enter your choice: ");
}

void start_game(const char *maze_file) {
    // Game initialization
    Config config;
    if (load_config(&config, "assets/default_config.txt") == 0) {
        fprintf(stderr, "Error loading configuration file.\n");
        return;
    }

    strcpy(config.maze_file, maze_file);

    char maze[MAX_ROWS][MAX_COLS];
    Player player;
    Enemy enemy;

    load_maze(maze, config.maze_file, &config.maze_rows, &config.maze_cols);
    generate_maze(maze, config.maze_rows, config.maze_cols, &config);
    initialize_player(&player);
    initialize_enemy(&enemy, maze, config.maze_rows, config.maze_cols);

    printf("Starting the game...\n");
    play_music("assets/sounds/background_music.wav");

    // Game loop
    int game_over = 0;
    char input;
    while (!game_over) {
        display_maze(maze, config.maze_rows, config.maze_cols);
        printf("\nScore: %d\n", player.score);
        printf("Enter your move: ");
        scanf(" %c", &input);

        if (input == 'q' || input == 'Q') {
            printf("Thanks for playing!\n");
            play_sound("assets/sounds/game_over.wav");
            break;
        }

        if (move_player(&player, maze, input)) {
            printf("You completed the maze!\n");
            progress_exists = true; // Update progress flag
            strcpy(last_completed_maze, maze_file); // Save last maze
            break;
        }

        move_enemy(&enemy, &player, maze);

        if (enemy.x == player.x && enemy.y == player.y) {
            printf("Game Over! You were caught by the enemy!\n");
            game_over = 1;
            play_sound("assets/sounds/game_over.wav");
        }
    }

    cleanup_audio();
}

void handle_menu() {
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start_game("assets/mazes/maze_easy.txt");
                break;
            case 2:
                if (progress_exists) {
                    printf("Continuing from your last maze: %s\n", last_completed_maze);
                    start_game(last_completed_maze);
                } else {
                    printf("No progress to continue.\n");
                }
                break;
            case 3:
                printf("Loading saved game progress (feature not implemented).\n");
                break;
            case 4: {
                printf("Select a level:\n1. Easy\n2. Medium\n3. Hard\nEnter your choice: ");
                int level_choice;
                scanf("%d", &level_choice);
                const char *maze_file = (level_choice == 1) ? "assets/mazes/maze_easy.txt" :
                                        (level_choice == 2) ? "assets/mazes/maze_medium.txt" :
                                        "assets/mazes/maze_hard.txt";
                start_game(maze_file);
                break;
            }
            case 5:
                printf("\nSettings Menu:\n1. Audio Settings\n2. Gameplay Settings\n3. Back to Main Menu\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}

int main() {
    handle_menu();
    return 0;
}