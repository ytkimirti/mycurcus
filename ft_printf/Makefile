NAME=libftprintf.a
LIBFT=libft/libft.a

# REMOVE THIS WHEN PUSHING
SRCS=printf.c utils.c
OBJS=$(SRCS:.c=.o)

BONUS=
BONUS_OBJS=$(BONUS:.c=.o)

CC=gcc
CFLAGS=-Wall -Wextra -Werror

TEST=test.c
TEST_OBJS=$(TEST:.c=.o)
TEST_LIB=./munit/munit.c
TEST_LIB_OBJS=$(TEST_LIB:.c=.o)

.PHONY: all clean fclean re bonus makelib test

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

#bonus: $(OBJS) $(BONUS_OBJS)
	#$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(BONUS_OBJS)

test: makelib $(TEST_OBJS) $(OBJS) $(TEST_LIB_OBJS)
	gcc -o test $^
	./test

