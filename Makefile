# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 08:58:18 by bcorte-r          #+#    #+#              #
#    Updated: 2024/01/18 17:10:38 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS =	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
    	ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
    	ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

BONUS_SRCS = ft_lstnew.c \
			 ft_lstadd_front.c

MISC_SRCS = ft_isdigit_str.c

OBJS = $(SRCS:%.c=bin/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=bin/%.o)
MISC_OBJS = $(MISC_SRCS:%.c=bin/%.o)
FT_PRINTF = src/modules/ft_printf/bin/*.o
GNL = src/modules/ft_get_next_line/bin/*.o

all: dir $(NAME)

dir:
	@mkdir -p bin
	@mkdir -p build

bin/%.o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJS) $(BONUS_OBJS) $(MISC_OBJS) 
	@$(MAKE) -C src/modules/ft_printf 
	@$(MAKE) -C src/modules/ft_get_next_line
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS) $(MISC_OBJS) $(FT_PRINTF) $(GNL)
	mv $(NAME) build/

clean:
	rm -rf $(OBJS) $(BONUS_OBJS) $(MISC_OBJS)
	$(MAKE) -C src/modules/ft_printf clean
	$(MAKE) -C src/modules/ft_get_next_line clean

fclean: clean
	rm -r build/$(NAME)
	rm -rf build

re: fclean all
