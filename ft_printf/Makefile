NAME=libftprintf.a
LIBFT=libft/libft.a

# REMOVE THIS WHEN PUSHING
SRCS=printf.c utils.c
OBJS=$(SRCS:.c=.o)

BONUS=
BONUS_OBJS=$(BONUS:.c=.o)

CC=gcc
CFLAGS=-Wall -Wextra -Werror

.PHONY: all clean fclean re bonus makelib

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
