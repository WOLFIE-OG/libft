# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wolfie <wolfie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 08:58:18 by bcorte-r          #+#    #+#              #
#    Updated: 2024/01/17 15:40:13 by wolfie           ###   ########.fr        #
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

FT_PRINTF_SRCS = ft_printf.c \
				 ft_printf_arth_u.c \
				 ft_printf_arth.c \
				 ft_printf_char.c \
				 ft_printf_ptr.c \
				 ft_printf_str.c \
				 ft_printf_utils.c

GNL_SRCS =	ft_get_next_line_utils.c \
		   	ft_get_next_line.c

BONUS_SRCS = ft_lstnew.c \
			 ft_lstadd_front.c

MISC_SRCS = ft_isdigit_str.c

OBJS = $(SRCS:.c=.o)
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
MISC_OBJS = $(MISC_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS) $(BONUS_OBJS) $(MISC_OBJS)
	ar rcs $(NAME) $(OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS) $(BONUS_OBJS) $(MISC_OBJS)

clean:
	rm -rf $(OBJS) $(FT_PRINTF_OBJS) $(GNL_OBJS) $(BONUS_OBJS) $(MISC_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
