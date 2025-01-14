CC = gcc
CFLAGS = -Iinclude -Wall -g
SRC = src/main.c src/maze.c src/player.c src/enemy.c src/utils.c
OBJ = $(SRC:.c=.o)
EXEC = maze_explorer

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

clean:
	rm -f $(OBJ) $(EXEC)