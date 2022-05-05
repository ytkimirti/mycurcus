
BIN ?= so_long
OBJ_DIR ?= obj

LIBS = libft/libft.a libmlx/libmlx.a -framework OpenGL -framework AppKit

SRC=main.c utils.c player.c map.c error_handling.c load_images.c render.c \
	 renderutils.c keys.c renderwrapper.c binaryutils.c renderdigits.c \
	 enemy.c loadutils.c

# Color Aliases
CLRLINE = \033[A\33[2KT\r
RST = \033[0;39m
GRY = \033[0;90m
RED = \033[0;91m
GRN = \033[0;92m
YLW = \033[0;93m
BLU = \033[0;94m
MAG = \033[0;95m
CYN = \033[0;96m
WHT = \033[0;97m

SHELL=/bin/bash
UNAME = $(shell uname -s)

CDEBUG ?= #-g3 #-fsanitize=address

# Make variables
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc -MD

NAME = $(BIN)

PRINTF = LC_NUMERIC="en_US.UTF-8" printf

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Progress vars
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif
SRC_COUNT := 1
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

all: $(NAME)

$(NAME): | pre

$(NAME): $(OBJ)
	@echo "COMPILING"
	$(CC) $(CFLAGS) $(CDEBUG) $(OBJ) $(LIBS) -o $@
	@$(PRINTF) "$(GRN)$(NAME) is up to date!$(RST)\n"

pre:
	@echo "Pre job"

$(OBJ): | $(OBJ_DIR)

install_packages:
	@$(PRINTF) "INSTALLING PACKAGES\n\n"
	@if [ ! -d "libft" ]; then \
		git clone --depth 1 https://github.com/ytkimirti/libft.git; \
		fi
	@make all -j8 -C libft/
	@make all -j8 -C libmlx/

$(OBJ_DIR)/%.o: %.c
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "$(CLRLINE)[ %d/%d (%d%%) ] Compiling $(BLU)$<$(RST)...\n" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) $(CDEBUG) -c $< -o $@

debug: CFLAGS += -g
debug: re

address: CFLAGS += -fsanitize=address -g
address: re

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(PRINTF) "$(CYN)Cleaning up object files in $(OBJ_DIR)...$(RST)\n"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(PRINTF) "$(CYN)Cleaning up $(NAME)$(RST)\n"

norminette:
	@if [ -d "libft" ]; then \
		make norminette -C libft\; \
	fi
	@$(PRINTF) "$(CYN)Checking norm for $(NAME)...$(RST)\n"
	@norminette -R CheckForbiddenSourceHeader

re: fclean
	@make all

git:
	git add .
	git commit
	git push

# ----------  IMAGE CONVERSION -----------
SRC_ASSETS_DIR := assets_png
DST_ASSETS_DIR := assets

SRC_ASSETS := $(wildcard $(SRC_ASSETS_DIR)/*.png)

DST_ASSETS := $(SRC_ASSETS:$(SRC_ASSETS_DIR)/%.png=$(DST_ASSETS_DIR)/%.xpm)

MAGICK_FLAGS=-scale 400% -filter box

$(DST_ASSETS): $(DST_ASSETS_DIR)/%.xpm: $(SRC_ASSETS_DIR)/%.png
	@mkdir -p $(dir $@)
	magick $< $(MAGICK_FLAGS) $@

-include $(OBJ_DIR)/*.d

.PHONY: all clean fclean re bonus norminette create_dirs install_packages git re
