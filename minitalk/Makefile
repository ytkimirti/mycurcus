CC=gcc
CFLAGS=-Wall -Werror -Wextra -g

all: server client

run: all
	./server


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

server: server.o
	$(CC) -L./libft -lft $^ -o $@

client: client.o
	$(CC) -L./libft -lft $^ -o $@
