# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wolfie <wolfie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 17:10:44 by wolfie            #+#    #+#              #
#    Updated: 2024/01/16 17:10:45 by wolfie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXECUTABLE_NAME = libft.a
COMPILER = cc
CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = bin

SRCS = $(wildcard ft_*.c)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(EXECUTABLE_NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(EXECUTABLE_NAME): $(OBJS)
	@ar rcs $(EXECUTABLE_NAME) $(OBJ_DIR)/*

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -r $(EXECUTABLE_NAME)

re: fclean
	make

.PHONY: all clean fclean re