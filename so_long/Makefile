NAME=so_long
LIBFT=libft/libft.a
LIBFT_DIR=./libft

SRCS=main.c utils.c player.c map.c error_handling.c load_images.c render.c \
	 renderutils.c keys.c renderwrapper.c binaryutils.c
HEADERS=so_long.h
OBJS=$(SRCS:.c=.o)

CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -Imlx -Ilibft

TEST_MAP=test.ber

# ----------  IMAGE CONVERSION -----------
SRC_ASSETS_DIR := assets_png
DST_ASSETS_DIR := assets

SRC_ASSETS := $(wildcard $(SRC_ASSETS_DIR)/*.png)

DST_ASSETS := $(SRC_ASSETS:$(SRC_ASSETS_DIR)/%.png=$(DST_ASSETS_DIR)/%.xpm)

MAGICK_FLAGS=-scale 400% -filter box

.PHONY: all clean fclean sclean sre re bonus test makelib

all: makelib $(DST_ASSETS) $(NAME)

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


$(DST_ASSETS): $(DST_ASSETS_DIR)/%.xpm: $(SRC_ASSETS_DIR)/%.png
	@mkdir -p $(dir $@)
	magick $< $(MAGICK_FLAGS) $@
