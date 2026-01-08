# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 18:44:17 by adpinhei          #+#    #+#              #
#    Updated: 2026/01/08 18:00:35 by adpinhei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := awesomePhoneBook

CC := c++

FLAGS = -Wall -Wextra -Werror -std=c++98

vpath %.h includes

BUILD_DIR := build

SRC_FILES := 

OBJ_FILES := $(SRC_FILES:%.c=$(BUILD_DIR)/%.o)

.PHONY: all clean fclean re

all: $(BUILD_DIR) $(NAME)

$(BUILD_DIR):
	@mkdir -p $@
	@echo "Creating $(BUILD_DIR)"
	@echo "Compiled objects."

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	@$(CC) $(FLAGS) $(OBJ_FILES) -o $@
	@echo "Compiled $(NAME)"

clean:
	@rm -rf $(BUILD_DIR)
	@echo "Cleaned object files."

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned executable $(NAME)"

re: fclean all