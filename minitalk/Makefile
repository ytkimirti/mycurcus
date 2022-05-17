CC=gcc
CFLAGS=-Wall -Werror -Wextra

CLIENT = client.c
SERVER = server.c

all: server client

bonus: CLIENT = client_bonus.c
bonus: SERVER = server_bonus.c
bonus: all

server: libft/libft.a $(SERVER:.c=.o)
	$(CC) -L./libft -lft $^ -o $@

client: libft/libft.a $(CLIENT:.c=.o)
	$(CC) -L./libft -lft $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Installing libraries
libft/libft.a:
	@if [ ! -d "libft" ]; then \
		git clone --depth 1 https://github.com/ytkimirti/libft.git; \
	fi
	@make all -j8 -C libft/

clean:
	rm -rf server.o client.o server_bonus.o client_bonus.o

fclean: clean
	rm -rf server client

.PHONY: all
