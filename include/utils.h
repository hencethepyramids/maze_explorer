#ifndef UTILS_H
#define UTILS_H

typedef struct {
    int maze_rows;
    int maze_cols;
    char player_symbol;
    char exit_symbol;
    char wall_symbol;
    char path_symbol;
} Config;

// Function prototypes
void load_config(Config *config, const char *file_path);

#endif