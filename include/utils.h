#ifndef UTILS_H
#define UTILS_H

typedef struct {
    char maze_file[100];
    int maze_rows;
    int maze_cols;
    char player_symbol;
    char exit_symbol;
    char wall_symbol;
    char path_symbol;
} Config;

void delay(int milliseconds);

// Function prototypes
int load_config(Config *config, const char *filename);

#endif