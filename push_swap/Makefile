NAME = push_swap

CC = gcc

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -L./libft -lft

RUNFLAGS = 

all: makelib $(NAME)

srun: run

run: all
	./$(NAME) $(RUNFLAGS)

makelib:
	make -C ./libft bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	$(CC) $(LFLAGS) -o $@ $^

clean:
	rm -rf $(OBJS)
