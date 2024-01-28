# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 08:58:18 by bcorte-r          #+#    #+#              #
#    Updated: 2024/01/26 19:22:59 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = 	cc
CFLAGS = -Wall -Wextra -Werror
NAME = 	libft.a
MODULES = src/modules
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

BONUS_SRCS =	ft_lstnew.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstsize.c

MISC_SRCS = 	ft_abs.c \
				ft_isnegative.c \
				ft_numlen.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strstr.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_sqrt.c \
				ft_isprime.c \
				ft_range.c \
				ft_putnbr.c \
				ft_swap.c \
				ft_putendl.c \
				ft_ischeck_str.c \
				ft_islower.c \
				ft_isupper.c \
				ft_atol.c \
				ft_binary.c

OBJS = 			$(SRCS:%.c=obj/%.o)
BONUS_OBJS = 	$(BONUS_SRCS:%.c=obj/%.o)
MISC_OBJS = 	$(MISC_SRCS:%.c=obj/%.o)
FT_PRINTF = 	$(MODULES)/ft_printf/obj/*.o
GNL = 			$(MODULES)/ft_get_next_line/obj/*.o

all: dir $(NAME)

dir:
	mkdir -p obj
	mkdir -p build

obj/%.o: src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJS) $(BONUS_OBJS) $(MISC_OBJS) 
	$(MAKE) -C $(MODULES)/ft_printf 
	$(MAKE) -C $(MODULES)/ft_get_next_line
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS) $(MISC_OBJS) $(FT_PRINTF) $(GNL)
	mv $(NAME) build/

clean:
	rm -rf $(OBJS) $(BONUS_OBJS) $(MISC_OBJS)
	rm -rf obj
	$(MAKE) -C $(MODULES)/ft_printf clean
	$(MAKE) -C $(MODULES)/ft_get_next_line clean

fclean: clean
	rm -rf build/$(NAME)
	rm -rf build

re: fclean all

add_test:
	mkdir -p tests/
	wget https://gist.githubusercontent.com/WOLFIE-OG/5fe84b7e6f5ba7b7dc0ed503c6504d78/raw/27fff2ca0ea82c5e63b32bbfa499081b15330d84/ANSI-color-codes.h -O tests/ANSI-color-codes.h
	wget https://gist.githubusercontent.com/WOLFIE-OG/5fe84b7e6f5ba7b7dc0ed503c6504d78/raw/27fff2ca0ea82c5e63b32bbfa499081b15330d84/program.c -O tests/program.c

remove_test:
	rm -rf tests/

test: all add_test
	$(CC) tests/ANSI-color-codes.h tests/program.c -Lbuild -lft -lbsd -o test.bin -g
	./test.bin
	rm test.bin
	$(MAKE) remove_test

.PHONY: all clean fclean re