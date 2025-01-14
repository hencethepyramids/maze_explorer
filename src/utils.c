#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void load_config(Config *config, const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open configuration file: %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    // Initialize default values
    config->maze_rows = 10;
    config->maze_cols = 10;
    config->player_symbol = 'P';
    config->exit_symbol = 'E';
    config->wall_symbol = '#';
    config->path_symbol = ' ';

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Ignore comments and empty lines
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }

        // Parse configuration key-value pairs
        char key[50], value[50];
        if (sscanf(line, "%[^=]=%s", key, value) == 2) {
            if (strcmp(key, "maze_rows") == 0) {
                config->maze_rows = atoi(value);
            } else if (strcmp(key, "maze_cols") == 0) {
                config->maze_cols = atoi(value);
            } else if (strcmp(key, "player_symbol") == 0) {
                config->player_symbol = value[0];
            } else if (strcmp(key, "exit_symbol") == 0) {
                config->exit_symbol = value[0];
            } else if (strcmp(key, "wall_symbol") == 0) {
                config->wall_symbol = value[0];
            } else if (strcmp(key, "path_symbol") == 0) {
                config->path_symbol = value[0];
            }
        }
    }

    fclose(file);
}