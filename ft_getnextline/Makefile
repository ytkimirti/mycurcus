NAME=a.out

SRCS=get_next_line.c get_next_line_utils.c
OBJS=$(SRCS:.c=.o)

BONUS=
BONUS_OBJS=$(BONUS:.c=.o)

CC=gcc
CFLAGS=-I. -Wall -Wextra -Werror

TEST=test.c
TEST_OBJS=$(TEST:.c=.o)
TEST_LIB=./munit/munit.c

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(BONUS_OBJS)

test: $(OBJS) $(TEST_OBJS) $(TEST_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $^
