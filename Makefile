# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: husaltam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 14:33:07 by husaltam          #+#    #+#              #
#    Updated: 2025/05/18 14:35:31 by husaltam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================= COMPILER CONFIG ============================= #
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -Iincludes -Ilib/ft_printf -Ilib/get_next_line

# ============================= DIRECTORIES ================================= #
SRC_DIR := src
LIB_DIR := lib

FT_PRINTF_DIR := $(LIB_DIR)/ft_printf
GNL_DIR      := $(LIB_DIR)/get_next_line

# ============================= SOURCE FILES ================================ #
PUSH_SWAP_MAIN := $(SRC_DIR)/stack_parser_args/main.c
CHECKER_MAIN   := $(SRC_DIR)/checker_bonus/checker_bonus.c

SRC_FILES := \
	$(filter-out $(PUSH_SWAP_MAIN) $(CHECKER_MAIN), \
	$(shell find $(SRC_DIR) -name "*.c")) \
	$(shell find $(FT_PRINTF_DIR) -name "*.c") \
	$(shell find $(GNL_DIR) -name "*.c")

# ============================= OBJECTS ===================================== #
OBJ_DIR := obj

OBJS := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
PUSH_SWAP_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(PUSH_SWAP_MAIN))
CHECKER_OBJ   := $(patsubst %.c, $(OBJ_DIR)/%.o, $(CHECKER_MAIN))

# ============================= TARGETS ===================================== #
PUSH_SWAP := push_swap
CHECKER   := checker

# ============================= RULES ======================================= #

all: $(PUSH_SWAP)

bonus: $(CHECKER)

$(PUSH_SWAP): $(OBJS) $(PUSH_SWAP_OBJ)
	@echo "Linking $(PUSH_SWAP)..."
	$(CC) $(CFLAGS) $^ -o $@

$(CHECKER): $(OBJS) $(CHECKER_OBJ)
	@echo "Linking $(CHECKER)..."
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(PUSH_SWAP) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re

