NAME=so_long
LIBFT=libft/libft.a
LIBFT_DIR=./libft

# REMOVE THIS WHEN PUSHING
SRCS=main.c utils.c player.c map.c error_handling.c
OBJS=$(SRCS:.c=.o)

BONUS=
BONUS_OBJS=$(BONUS:.c=.o)

CC=gcc
CFLAGS=-g -Wall -Wextra -Imlx
#CFLAGS=-Wall -Wextra -Werror -Imlx

TEST=
TEST_OBJS=$(TEST:.c=.o)
TEST_LIB=./munit/munit.c
TEST_LIB_OBJS=$(TEST_LIB:.c=.o)

TEST_MAP=test.ber

.PHONY: all clean fclean re bonus test makelib


all: makelib $(NAME)

run: all
	./$(NAME) $(TEST_MAP)


makelib:
	make -C $(LIBFT_DIR) bonus

debug: $(NAME)
	echo ">------  DEBUG MODE --------<"
	lldb ./$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L./libmlx -L$(LIBFT_DIR) -lmlx -lft -framework OpenGL -framework AppKit -o $(NAME)

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

