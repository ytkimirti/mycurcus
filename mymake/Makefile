# Project vars
BIN ?= so_long
BIN_DIR ?= bin

SRC_DIR ?= src
OBJ_DIR ?= obj

SRC ?= main.c

LIBFT ?= libft/libft.a
LIBFT_REPO ?= https://github.com/ytkimirti/libft.git

# Color Aliases
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

CDEBUG ?= -g3 #-fsanitize=address

# Properties for MacOS

ifeq ($(UNAME), Linux)
	# Properties for Linux
	LEAKS =  valgrind --leak-check=full --show-leak-kinds=all -s -q 
endif

# Make variables
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc -MD

NAME = $(BIN_DIR)/$(BIN)

PRINTF = LC_NUMERIC="en_US.UTF-8" printf

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Progress vars
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

all: $(NAME)

$(NAME): create_dirs download_packages $(OBJ)
	@$(CC) $(CFLAGS) $(CDEBUG) $(OBJ) $(LIBFT) -o $@
	@$(PRINTF) "\r%100s\r$(GRN)$(BIN) is up to date!$(RST)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLU)$<$(RST)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) $(CDEBUG) -c $< -o $@

bonus: all

download_packages:
	@if [ ! -d "libft" ]; then \
		git clone $(LIBFT_REPO); \
	fi
	@make all -C libft/

delete_packages:
	rm -rf libft

run: all
	./$(NAME) $(ARGS)

create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

clean:
	@$(PRINTF) "$(CYN)Cleaning up object files in $(BIN)...$(RST)\n"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) -r $(BIN_DIR)
	@$(PRINTF) "$(CYN)Removed $(NAME)$(RST)\n"

norminette:
	@if [ -d "libft" ]; then \
		make norminette -C libft/; \
	fi
	@$(PRINTF) "$(CYN)\nChecking norm for $(BIN)...$(RST)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR)

re: fclean
	@make all

git:
	git add .
	git commit
	git push

-include $(OBJ_DIR)/*.d

.PHONY: all clean fclean bonus download_packages norminette create_dirs git re
