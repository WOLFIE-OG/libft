# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 17:49:05 by otodd             #+#    #+#              #
#    Updated: 2024/02/14 19:54:51 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW=\033[1;33m
RED=\033[1;31m
GREEN=\033[1;32m
BLUE=\033[0;34m
NC=\033[0m
	
CC				= 	cc
CFLAGS 			= 	-Wall -Wextra -Werror
NAME 			= 	libft.a
MODULES 		= 	src/modules
OBJ_DIR			= 	obj
SRC_DIR 		= 	src
FT_PRINTF_DIR	= 	$(MODULES)/ft_printf
GNL_DIR 		= 	$(MODULES)/ft_get_next_line

SRCS 			=	$(SRC_DIR)/checks/ft_isdigit.c				\
					$(SRC_DIR)/checks/ft_isalpha.c				\
					$(SRC_DIR)/checks/ft_isalnum.c				\
					$(SRC_DIR)/checks/ft_isascii.c				\
					$(SRC_DIR)/checks/ft_isprint.c 				\
					$(SRC_DIR)/strings/ft_strlen.c 				\
					$(SRC_DIR)/strings/ft_strlcpy.c 			\
					$(SRC_DIR)/strings/ft_strlcat.c 			\
					$(SRC_DIR)/strings/ft_strchr.c 				\
					$(SRC_DIR)/strings/ft_strrchr.c 			\
					$(SRC_DIR)/strings/ft_strncmp.c 			\
					$(SRC_DIR)/strings/ft_strnstr.c 			\
					$(SRC_DIR)/strings/ft_strdup.c 				\
					$(SRC_DIR)/strings/ft_substr.c 				\
					$(SRC_DIR)/strings/ft_strjoin.c 			\
					$(SRC_DIR)/strings/ft_strtrim.c 			\
					$(SRC_DIR)/strings/ft_split.c 				\
					$(SRC_DIR)/strings/ft_strmapi.c 			\
					$(SRC_DIR)/strings/ft_striteri.c 			\
					$(SRC_DIR)/io/ft_putchar_fd.c 				\
					$(SRC_DIR)/io/ft_putstr_fd.c 				\
					$(SRC_DIR)/io/ft_putendl_fd.c 				\
					$(SRC_DIR)/io/ft_putnbr_fd.c 				\
					$(SRC_DIR)/memory/ft_memset.c 				\
					$(SRC_DIR)/memory/ft_bzero.c 				\
					$(SRC_DIR)/memory/ft_memcpy.c 				\
					$(SRC_DIR)/memory/ft_memmove.c 				\
					$(SRC_DIR)/memory/ft_memchr.c 				\
					$(SRC_DIR)/memory/ft_memcmp.c 				\
					$(SRC_DIR)/memory/ft_calloc.c 				\
					$(SRC_DIR)/converters/ft_toupper.c			\
					$(SRC_DIR)/converters/ft_tolower.c			\
					$(SRC_DIR)/converters/ft_atoi.c 			\
					$(SRC_DIR)/converters/ft_itoa.c 	

BONUS_SRCS		= 	$(SRC_DIR)/list/ft_lstnew.c 				\
					$(SRC_DIR)/list/ft_lstlast.c 				\
					$(SRC_DIR)/list/ft_lstadd_back.c 			\
					$(SRC_DIR)/list/ft_lstadd_front.c 			\
					$(SRC_DIR)/list/ft_lstclear.c				\
					$(SRC_DIR)/list/ft_lstdelone.c				\
					$(SRC_DIR)/list/ft_lstiter.c 				\
					$(SRC_DIR)/list/ft_lstmap.c 				\
					$(SRC_DIR)/list/ft_lstsize.c

MISC_SRCS 		= 	$(SRC_DIR)/maths/ft_abs.c					\
					$(SRC_DIR)/maths/ft_sqrt.c 					\
					$(SRC_DIR)/checks/ft_isnegative.c 			\
					$(SRC_DIR)/checks/ft_isprime.c 				\
					$(SRC_DIR)/checks/ft_iswhitespace.c 		\
					$(SRC_DIR)/checks/ft_ischeck_str.c 			\
					$(SRC_DIR)/checks/ft_islower.c 				\
					$(SRC_DIR)/checks/ft_isupper.c 				\
					$(SRC_DIR)/checks/ft_check_overflow.c		\
					$(SRC_DIR)/utils/ft_numlen.c				\
					$(SRC_DIR)/utils/ft_range.c 				\
					$(SRC_DIR)/utils/ft_max.c 					\
					$(SRC_DIR)/utils/ft_free_array.c 			\
					$(SRC_DIR)/utils/ft_strarraylen.c 			\
					$(SRC_DIR)/strings/ft_strcpy.c 				\
					$(SRC_DIR)/strings/ft_strncpy.c 			\
					$(SRC_DIR)/strings/ft_strcat.c 				\
					$(SRC_DIR)/strings/ft_strncat.c 			\
					$(SRC_DIR)/strings/ft_strstr.c 				\
					$(SRC_DIR)/strings/ft_strcmp.c 				\
					$(SRC_DIR)/io/ft_putchar.c 					\
					$(SRC_DIR)/io/ft_putstr.c 					\
					$(SRC_DIR)/io/ft_putendl.c 					\
					$(SRC_DIR)/io/ft_putnbr.c 					\
					$(SRC_DIR)/memory/ft_swap.c 				\
					$(SRC_DIR)/converters/ft_atol.c 			\
					$(SRC_DIR)/converters/ft_binary.c 

OBJS 			= 	$(OBJ_DIR)/ft_isdigit.o						\
					$(OBJ_DIR)/ft_isalpha.o 					\
					$(OBJ_DIR)/ft_isalnum.o 					\
					$(OBJ_DIR)/ft_isascii.o 					\
					$(OBJ_DIR)/ft_isprint.o 					\
					$(OBJ_DIR)/ft_strlen.o 						\
					$(OBJ_DIR)/ft_strlcpy.o 					\
					$(OBJ_DIR)/ft_strlcat.o 					\
					$(OBJ_DIR)/ft_strchr.o 						\
					$(OBJ_DIR)/ft_strrchr.o 					\
					$(OBJ_DIR)/ft_strncmp.o 					\
					$(OBJ_DIR)/ft_strnstr.o 					\
					$(OBJ_DIR)/ft_strdup.o 						\
					$(OBJ_DIR)/ft_substr.o 						\
					$(OBJ_DIR)/ft_strjoin.o 					\
					$(OBJ_DIR)/ft_strtrim.o 					\
					$(OBJ_DIR)/ft_split.o 						\
					$(OBJ_DIR)/ft_strmapi.o 					\
					$(OBJ_DIR)/ft_striteri.o					\
					$(OBJ_DIR)/ft_putchar_fd.o 					\
					$(OBJ_DIR)/ft_putstr_fd.o 					\
					$(OBJ_DIR)/ft_putendl_fd.o 					\
					$(OBJ_DIR)/ft_putnbr_fd.o 					\
					$(OBJ_DIR)/ft_memset.o 						\
					$(OBJ_DIR)/ft_bzero.o 						\
					$(OBJ_DIR)/ft_memcpy.o 						\
					$(OBJ_DIR)/ft_memmove.o 					\
					$(OBJ_DIR)/ft_memchr.o 						\
					$(OBJ_DIR)/ft_memcmp.o 						\
					$(OBJ_DIR)/ft_calloc.o 						\
					$(OBJ_DIR)/ft_toupper.o 					\
					$(OBJ_DIR)/ft_tolower.o 					\
					$(OBJ_DIR)/ft_atoi.o 						\
					$(OBJ_DIR)/ft_itoa.o 

MISC_OBJS 		= 	$(OBJ_DIR)/ft_abs.o 						\
					$(OBJ_DIR)/ft_sqrt.o 						\
					$(OBJ_DIR)/ft_isnegative.o 					\
					$(OBJ_DIR)/ft_isprime.o 					\
					$(OBJ_DIR)/ft_iswhitespace.o 				\
					$(OBJ_DIR)/ft_ischeck_str.o 				\
					$(OBJ_DIR)/ft_islower.o 					\
					$(OBJ_DIR)/ft_isupper.o 					\
					$(OBJ_DIR)/ft_check_overflow.o 				\
					$(OBJ_DIR)/ft_numlen.o 						\
					$(OBJ_DIR)/ft_range.o 						\
					$(OBJ_DIR)/ft_max.o 						\
					$(OBJ_DIR)/ft_free_array.o 					\
					$(OBJ_DIR)/ft_strarraylen.o					\
					$(OBJ_DIR)/ft_strcpy.o 						\
					$(OBJ_DIR)/ft_strncpy.o						\
					$(OBJ_DIR)/ft_strcat.o 						\
					$(OBJ_DIR)/ft_strncat.o						\
					$(OBJ_DIR)/ft_strstr.o 						\
					$(OBJ_DIR)/ft_strcmp.o 						\
					$(OBJ_DIR)/ft_putchar.o						\
					$(OBJ_DIR)/ft_putstr.o 						\
					$(OBJ_DIR)/ft_putendl.o						\
					$(OBJ_DIR)/ft_putnbr.o 						\
					$(OBJ_DIR)/ft_swap.o 						\
					$(OBJ_DIR)/ft_atol.o 						\
					$(OBJ_DIR)/ft_binary.o 						\

BONUS_OBJS		= 	$(OBJ_DIR)/ft_lstnew.o 						\
					$(OBJ_DIR)/ft_lstlast.o 					\
					$(OBJ_DIR)/ft_lstadd_back.o 				\
					$(OBJ_DIR)/ft_lstadd_front.o 				\
					$(OBJ_DIR)/ft_lstclear.o 					\
					$(OBJ_DIR)/ft_lstdelone.o 					\
					$(OBJ_DIR)/ft_lstiter.o 					\
					$(OBJ_DIR)/ft_lstmap.o 						\
					$(OBJ_DIR)/ft_lstsize.o

FT_PRINTF_OBJS 	= 	$(FT_PRINTF_DIR)/obj/ft_printf.o 			\
					$(FT_PRINTF_DIR)/obj/ft_printf_arth_u.o 	\
					$(FT_PRINTF_DIR)/obj/ft_printf_arth.o 		\
					$(FT_PRINTF_DIR)/obj/ft_printf_char.o 		\
					$(FT_PRINTF_DIR)/obj/ft_printf_ptr.o 		\
					$(FT_PRINTF_DIR)/obj/ft_printf_str.o 		\
					$(FT_PRINTF_DIR)/obj/ft_printf_utils.o 		\
					$(FT_PRINTF_DIR)/obj/ft_printf_char_array.o	\
					$(FT_PRINTF_DIR)/obj/ft_printf_nbr_array.o 	\
					$(FT_PRINTF_DIR)/obj/ft_printf_linked_list.o

GNL_OBJS 		= 	$(GNL_DIR)/obj/ft_get_next_line.o 			\
					$(GNL_DIR)/obj/ft_get_next_line_utils.o

AR_COMMAND		= ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS) $(MISC_OBJS)
BUILD_DIR 		= build

all: dir $(NAME)

dir:
	@if [ ! -d "obj" ]; then \
		echo "[$(GREEN)LIBFT$(NC)]     Creating obj directory..."; \
		mkdir -p obj; \
	fi
	@if [ ! -d "$(BUILD_DIR)" ]; then \
		echo "[$(GREEN)LIBFT$(NC)]     Creating build directory..."; \
		mkdir -p $(BUILD_DIR); \
	fi

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c
	@echo "[$(GREEN)LIBFT$(NC)]     Compiling $< --> $@"
	@$(CC) -o $@ -c $< $(CFLAGS) -I../include/libft.h

check_modules:
	@if [ ! -d "$(FT_PRINTF_DIR)" ]; then \
		echo "[$(YELLOW)LIBFT$(NC)]     Warning: ft_printf module directory does not exist. Skipping its inclusion."; \
	elif [ ! -f "$(FT_PRINTF_DIR)/include/ft_printf.h" ]; then \
		echo "[$(YELLOW)LIBFT$(NC)]     Warning: ft_printf module directory exists but is empty. Skipping its inclusion."; \
	else \
		$(MAKE) -s -C $(FT_PRINTF_DIR) module; \
	fi
	@if [ ! -d "$(GNL_DIR)" ]; then \
		echo "[$(YELLOW)LIBFT$(NC)]     Warning: ft_get_next_line module directory does not exist. Skipping its inclusion."; \
	elif [ ! -f "$(GNL_DIR)/include/ft_get_next_line.h" ]; then \
		echo "[$(YELLOW)LIBFT$(NC)]     Warning: ft_get_next_line module directory exists but is empty. Skipping its inclusion."; \
	else \
		$(MAKE) -s -C $(GNL_DIR) module; \
	fi

$(NAME): $(OBJS) $(BONUS_OBJS) $(MISC_OBJS) check_modules
	@echo "[$(GREEN)LIBFT$(NC)]     Creating $(NAME)..."
	@if [ -d "$(FT_PRINTF_DIR)" ]; then \
		echo "[$(GREEN)LIBFT$(NC)]     Adding ft_printf module to $(NAME)..."; \
		$(AR_COMMAND) $(FT_PRINTF_OBJS); \
	fi
	@if [ -d "$(GNL_DIR)" ]; then \
		echo "[$(GREEN)LIBFT$(NC)]     Adding ft_get_next_line module to $(NAME)..."; \
		$(AR_COMMAND) $(GNL_OBJS); \
	fi
	@$(AR_COMMAND)
	@mv $(NAME) $(BUILD_DIR)/

check_modules_clean:
	@if [ -d "$(FT_PRINTF_DIR)" ]; then \
		if [ -f "$(FT_PRINTF_DIR)/include/ft_printf.h" ]; then \
			echo "[$(BLUE)LIBFT$(NC)]     Cleaning ft_printf module."; \
			$(MAKE) -s -C $(FT_PRINTF_DIR) clean; \
		else \
			echo "[$(RED)LIBFT$(NC)]     ft_printf module is not clean, skipping cleaning."; \
		fi \
	else \
		echo "[$(YELLOW)LIBFT$(NC)]     Warning: ft_printf module directory does not exist. Skipping cleaning."; \
	fi
	@if [ -d "$(GNL_DIR)" ]; then \
		if [ -f "$(GNL_DIR)/include/ft_get_next_line.h" ]; then \
			echo "[$(BLUE)LIBFT$(NC)]     Cleaning ft_get_next_line module."; \
			$(MAKE) -s -C $(GNL_DIR) clean; \
		else \
			echo "[$(RED)LIBFT$(NC)]     ft_get_next_line module is not clean, skipping cleaning."; \
		fi \
	else \
		echo "[$(YELLOW)LIBFT$(NC)]     Warning: ft_get_next_line module directory does not exist. Skipping cleaning."; \
	fi

clean: check_modules_clean
	@echo "[$(YELLOW)LIBFT$(NC)]     Cleaning object files..."
	@rm -rf $(OBJS) $(BONUS_OBJS) $(MISC_OBJS)
	@rm -rf obj

fclean: clean
	@echo "[$(RED)LIBFT$(NC)]     Cleaning build directory..."
	@rm -rf $(BUILD_DIR)

re: fclean all

test: all
	@echo "[$(GREEN)LIBFT$(NC)]      Running tests..."
	@$(CC) tests/program.c -Lbuild -lft -lbsd -o test.bin
	./test.bin

.PHONY: all clean fclean re