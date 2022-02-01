NAME=so_long
LIBFT=libft/libft.a
LIBFT_DIR=./libft

# REMOVE THIS WHEN PUSHING
SRCS=main.c utils.c player.c map.c error_handling.c load_images.c render.c \
	 renderutils.c keys.c renderwrapper.c
HEADERS=so_long.h
OBJS=$(SRCS:.c=.o)

BONUS=yusuf.c yusuf2.c
#BONUS_OBJS=$(BONUS:.c=.o)
BONUS_OBJS=yusuf.o yusuf2.o

CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -Imlx -Ilibft
#CFLAGS=-Wall -Wextra -Werror -Imlx

TEST=
TEST_OBJS=$(TEST:.c=.o)
TEST_LIB=./munit/munit.c
TEST_LIB_OBJS=$(TEST_LIB:.c=.o)

TEST_MAP=test.ber

.PHONY: all clean fclean sclean sre re bonus test makelib


all: makelib $(NAME)

run: all
	./$(NAME) $(TEST_MAP)

srun: sre
	./$(NAME) $(TEST_MAP)

makelib:
	make -C $(LIBFT_DIR) bonus

debug: $(NAME)
	echo ">------  DEBUG MODE --------<"
	lldb ./$(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(OBJS) -L./libmlx -L$(LIBFT_DIR) -lmlx -lft -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(TEST_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

sclean: clean
	rm -f $(NAME)

re: fclean all
sre: sclean all

#SRC_ASSETS_DIR=assets_png
#DST_ASSETS_DIR=assets

#SRC_PNG=$(wildcard $(SRC_ASSETS_DIR)*.png)

#DST_XPM=$(SRC_PNG:.png=.xpm)

#MAGICK_FLAGS=-scale 400% -filter box

#convert: $
