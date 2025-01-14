CC = gcc
CFLAGS = -Iinclude -Wall -g
CFLAGS += $(shell pkg-config --cflags sdl2 SDL2_mixer)
LDFLAGS = $(shell pkg-config --libs sdl2 SDL2_mixer)
SRC = src/main.c src/maze.c src/player.c src/enemy.c src/utils.c src/audio.c
OBJ = $(SRC:.c=.o)
EXEC = maze_explorer

all: $(EXEC)

$(EXEC): $(OBJ)
	@echo "Include paths: $(CFLAGS)"
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)