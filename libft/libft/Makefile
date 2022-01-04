NAME=libft.a

SRCS=*.c

OBJS=$(SRCS:.c=.o)

BONUS=

BONUS_OBJS=$(BONUS:.c=.o)

CC=gcc
CFLAGS=-I. -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all:  $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

derle: test.o ft_strlen.o

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
