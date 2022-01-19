NAME=fdf
LIBFT=libft/libft.a
LIBFT_DIR=./libft

# REMOVE THIS WHEN PUSHING
SRCS=main.c utils.c
OBJS=$(SRCS:.c=.o)

BONUS=
BONUS_OBJS=$(BONUS:.c=.o)

CC=gcc
CFLAGS=-Wall -Wextra -Imlx
#CFLAGS=-Wall -Wextra -Werror -Imlx

TEST=
TEST_OBJS=$(TEST:.c=.o)
TEST_LIB=./munit/munit.c
TEST_LIB_OBJS=$(TEST_LIB:.c=.o)

.PHONY: all clean fclean re bonus test makelib

run: all
	./$(NAME)

all: $(NAME)

makelib:
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L./libmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(TEST_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

test: makelib $(TEST_OBJS) $(OBJS) $(TEST_LIB_OBJS)
	gcc -o test $^
	./test

