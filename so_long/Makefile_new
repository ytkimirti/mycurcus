BIN ?= libft.a
OBJ_DIR ?= obj

SRC=ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	 ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c  ft_memchr.c ft_memcmp.c \
	 ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	 ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	 ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	 ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strtrim.c \
	 ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	 ft_lstadd_back.c \
	 ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
	 ft_lstmap.c ft_lstnew.c ft_lstsize.c \
	 printf.c utils.c get_next_line_bonus.c \
	 sprintf.c ft_strjoinfre.c

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

CDEBUG ?= -g3 #-fsanitize=address

# Make variables
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = gcc -MD
AR = ar rcs

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

$(NAME): create_dirs $(OBJ)
	@$(AR) $@ $(OBJ)
	@$(PRINTF) "$(GRN)$(BIN) is up to date!$(RST)\n"

$(OBJ_DIR)/%.o: %.c
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "$(CLRLINE)[ %d/%d (%d%%) ] Compiling $(BLU)$<$(RST)...\n" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) $(CDEBUG) -c $< -o $@
create_dirs:
	@mkdir -p $(OBJ_DIR)

clean:
	@$(PRINTF) "$(CYN)Cleaning up object files in $(OBJ_DIR)...$(RST)\n"
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@$(RM) -rf $(BIN)
	@$(PRINTF) "$(CYN)Cleaning up $(NAME)$(RST)\n"

norminette:
	@$(PRINTF) "$(CYN)Checking norm...$(RST)\n"
	@norminette -R CheckForbiddenSourceHeader

re: fclean
	@make all

git:
	git add .
	git commit
	git push

-include $(OBJ_DIR)/*.d

.PHONY: all clean fclean bonus norminette create_dirs git re
