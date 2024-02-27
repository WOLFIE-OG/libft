# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 17:49:05 by otodd             #+#    #+#              #
#    Updated: 2024/02/27 16:39:09 by otodd            ###   ########.fr        #
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
OBJ_DIR			= 	obj
SRC_DIR 		= 	src
BUILD_DIR		=	build
MODULES 		= 	$(SRC_DIR)/modules
CHECK_DIR		=	$(SRC_DIR)/checks
STRING_DIR		=	$(SRC_DIR)/strings
IO_DIR			=	$(SRC_DIR)/io
MEMORY_DIR		=	$(SRC_DIR)/memory
CONVERTER_DIR	=	$(SRC_DIR)/converters
LIST_DIR		=	$(SRC_DIR)/list
UTIL_DIR		=	$(SRC_DIR)/utils
MATH_DIR		=	$(SRC_DIR)/maths

CHECK_OBJ		=	$(OBJ_DIR)/checks
STRING_OBJ		=	$(OBJ_DIR)/strings
IO_OBJ			=	$(OBJ_DIR)/io
MEMORY_OBJ		=	$(OBJ_DIR)/memory
CONVERTER_OBJ	=	$(OBJ_DIR)/converters
LIST_OBJ		=	$(OBJ_DIR)/list
UTIL_OBJ		=	$(OBJ_DIR)/utils
MATH_OBJ		=	$(OBJ_DIR)/maths

FT_PRINTF_DIR	= 	$(MODULES)/ft_printf
GNL_DIR 		= 	$(MODULES)/ft_get_next_line
OBJ_DIRS 		= 	$(OBJ_DIR)													\
					$(CHECK_OBJ)												\
					$(STRING_OBJ) 												\
					$(IO_OBJ)													\
					$(MEMORY_OBJ)												\
					$(CONVERTER_OBJ)											\
					$(LIST_OBJ)													\
					$(UTIL_OBJ)													\
					$(MATH_OBJ)
 
CHECK_SRCS		=	$(CHECK_DIR)/ft_isdigit.c									\
					$(CHECK_DIR)/ft_isalpha.c									\
					$(CHECK_DIR)/ft_isalnum.c									\
					$(CHECK_DIR)/ft_isascii.c									\
					$(CHECK_DIR)/ft_isprint.c 									\
					$(CHECK_DIR)/ft_isnegative.c 								\
					$(CHECK_DIR)/ft_isprime.c 									\
					$(CHECK_DIR)/ft_iswhitespace.c 								\
					$(CHECK_DIR)/ft_ischeck_str.c 								\
					$(CHECK_DIR)/ft_islower.c 									\
					$(CHECK_DIR)/ft_isupper.c 									\
					$(CHECK_DIR)/ft_check_overflow.c							\
					$(CHECK_DIR)/ft_ismath.c

STRING_SRCS		= 	$(STRING_DIR)/ft_strlen.c 									\
					$(STRING_DIR)/ft_strlen_n.c									\
					$(STRING_DIR)/ft_strlcpy.c 									\
					$(STRING_DIR)/ft_strlcat.c 									\
					$(STRING_DIR)/ft_strchr.c 									\
					$(STRING_DIR)/ft_strrchr.c 									\
					$(STRING_DIR)/ft_strncmp.c 									\
					$(STRING_DIR)/ft_strnstr.c 									\
					$(STRING_DIR)/ft_strdup.c 									\
					$(STRING_DIR)/ft_strndup.c 									\
					$(STRING_DIR)/ft_substr.c 									\
					$(STRING_DIR)/ft_strjoin.c 									\
					$(STRING_DIR)/ft_strtrim.c 									\
					$(STRING_DIR)/ft_split.c 									\
					$(STRING_DIR)/ft_strmapi.c 									\
					$(STRING_DIR)/ft_striteri.c 								\
					$(STRING_DIR)/ft_strcpy.c 									\
					$(STRING_DIR)/ft_strncpy.c 									\
					$(STRING_DIR)/ft_strcat.c 									\
					$(STRING_DIR)/ft_strncat.c 									\
					$(STRING_DIR)/ft_strstr.c 									\
					$(STRING_DIR)/ft_strcmp.c

IO_SRCS			=	$(IO_DIR)/ft_putchar_fd.c 									\
					$(IO_DIR)/ft_putstr_fd.c 									\
					$(IO_DIR)/ft_putendl_fd.c 									\
					$(IO_DIR)/ft_putnbr_fd.c 									\
					$(IO_DIR)/ft_putchar.c 										\
					$(IO_DIR)/ft_putstr.c 										\
					$(IO_DIR)/ft_putendl.c 										\
					$(IO_DIR)/ft_putnbr.c

MEMORY_SRCS		=	$(MEMORY_DIR)/ft_memset.c 									\
					$(MEMORY_DIR)/ft_bzero.c 									\
					$(MEMORY_DIR)/ft_memcpy.c 									\
					$(MEMORY_DIR)/ft_memmove.c 									\
					$(MEMORY_DIR)/ft_memchr.c 									\
					$(MEMORY_DIR)/ft_memcmp.c 									\
					$(MEMORY_DIR)/ft_calloc.c									\
					$(MEMORY_DIR)/ft_swap.c

CONVERTER_SRCS	=	$(CONVERTER_DIR)/ft_toupper.c								\
					$(CONVERTER_DIR)/ft_tolower.c								\
					$(CONVERTER_DIR)/ft_atoi.c 									\
					$(CONVERTER_DIR)/ft_itoa.c									\
					$(CONVERTER_DIR)/ft_atol.c 									\
					$(CONVERTER_DIR)/ft_binary.c

LIST_SRCS		= 	$(LIST_DIR)/ft_lstnew.c 									\
					$(LIST_DIR)/ft_lstlast.c 									\
					$(LIST_DIR)/ft_lstadd_back.c 								\
					$(LIST_DIR)/ft_lstadd_front.c 								\
					$(LIST_DIR)/ft_lstclear.c									\
					$(LIST_DIR)/ft_lstdelone.c									\
					$(LIST_DIR)/ft_lstiter.c 									\
					$(LIST_DIR)/ft_lstmap.c 									\
					$(LIST_DIR)/ft_lstsize.c

UTIL_SRCS		=	$(UTIL_DIR)/ft_numlen.c										\
					$(UTIL_DIR)/ft_range.c 										\
					$(UTIL_DIR)/ft_max.c 										\
					$(UTIL_DIR)/ft_free_array.c 								\
					$(UTIL_DIR)/ft_strarraylen.c

MATH_SRCS		=	$(MATH_DIR)/ft_abs.c										\
					$(MATH_DIR)/ft_sqrt.c

FT_PRINTF_OBJS 	= 	$(FT_PRINTF_DIR)/obj/ft_printf.o 							\
					$(FT_PRINTF_DIR)/obj/ft_printf_arth_u.o 					\
					$(FT_PRINTF_DIR)/obj/ft_printf_arth.o 						\
					$(FT_PRINTF_DIR)/obj/ft_printf_char.o 						\
					$(FT_PRINTF_DIR)/obj/ft_printf_ptr.o 						\
					$(FT_PRINTF_DIR)/obj/ft_printf_str.o 						\
					$(FT_PRINTF_DIR)/obj/ft_printf_utils.o 						\
					$(FT_PRINTF_DIR)/obj/ft_printf_char_array.o					\
					$(FT_PRINTF_DIR)/obj/ft_printf_nbr_array.o 					\
					$(FT_PRINTF_DIR)/obj/ft_printf_linked_list.o				\
					$(FT_PRINTF_DIR)/obj/ft_printf_arth_l.o


GNL_OBJS 		= 	$(GNL_DIR)/obj/ft_get_next_line.o 							\
					$(GNL_DIR)/obj/ft_get_next_line_utils.o

OBJS 			= 	$(CHECK_SRCS:$(CHECK_DIR)/%.c=$(CHECK_OBJ)/%.o) 			\
					$(STRING_SRCS:$(STRING_DIR)/%.c=$(STRING_OBJ)/%.o) 			\
					$(IO_SRCS:$(IO_DIR)/%.c=$(IO_OBJ)/%.o) 						\
					$(MEMORY_SRCS:$(MEMORY_DIR)/%.c=$(MEMORY_OBJ)/%.o) 			\
					$(CONVERTER_SRCS:$(CONVERTER_DIR)/%.c=$(CONVERTER_OBJ)/%.o)	\
					$(LIST_SRCS:$(LIST_DIR)/%.c=$(LIST_OBJ)/%.o) 				\
					$(UTIL_SRCS:$(UTIL_DIR)/%.c=$(UTIL_OBJ)/%.o) 				\
					$(MATH_SRCS:$(MATH_DIR)/%.c=$(MATH_OBJ)/%.o) 

AR_COMMAND		=	ar -rcs $(NAME) $(OBJS)
BUILD_DIR 		=	build

all: $(NAME)

dir:
	@for dir in $(OBJ_DIRS) $(BUILD_DIR); do \
		if [ ! -d "$$dir" ]; then \
			echo "[$(GREEN)LIBFT$(NC)]     Creating directory: $$dir"; \
			mkdir -p $$dir; \
		fi; \
	done

$(CHECK_OBJ)/%.o: $(CHECK_DIR)/%.c | dir
	@echo "[$(GREEN)LIBFT$(NC)]     Compiling $< --> $@"
	@$(CC) -o $@ -c $< $(CFLAGS) -I../include/libft.h

$(STRING_OBJ)/%.o: $(STRING_DIR)/%.c | dir
	@echo "[$(GREEN)LIBFT$(NC)]     Compiling $< --> $@"
	@$(CC) -o $@ -c $< $(CFLAGS) -I../include/libft.h

$(IO_OBJ)/%.o: $(IO_DIR)/%.c | dir
	@echo "[$(GREEN)LIBFT$(NC)]     Compiling $< --> $@"
	@$(CC) -o $@ -c $< $(CFLAGS) -I../include/libft.h

$(MEMORY_OBJ)/%.o: $(MEMORY_DIR)/%.c | dir
	@echo "[$(GREEN)LIBFT$(NC)]     Compiling $< --> $@"
	@$(CC) -o $@ -c $< $(CFLAGS) -I../include/libft.h

$(CONVERTER_OBJ)/%.o: $(CONVERTER_DIR)/%.c | dir
	@echo "[$(GREEN)LIBFT$(NC)]     Compiling $< --> $@"
	@$(CC) -o $@ -c $< $(CFLAGS) -I../include/libft.h

$(LIST_OBJ)/%.o: $(LIST_DIR)/%.c | dir
	@echo "[$(GREEN)LIBFT$(NC)]     Compiling $< --> $@"
	@$(CC) -o $@ -c $< $(CFLAGS) -I../include/libft.h

$(UTIL_OBJ)/%.o: $(UTIL_DIR)/%.c | dir
	@echo "[$(GREEN)LIBFT$(NC)]     Compiling $< --> $@"
	@$(CC) -o $@ -c $< $(CFLAGS) -I../include/libft.h

$(MATH_OBJ)/%.o: $(MATH_DIR)/%.c | dir
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

$(NAME): $(OBJS) check_modules
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
	@rm -rf $(OBJS)
	@rm -rf $(OBJ_DIRS)

fclean: clean
	@echo "[$(RED)LIBFT$(NC)]     Cleaning build directory..."
	@rm -rf $(BUILD_DIR)

re: fclean all

test: all
	@echo "[$(GREEN)LIBFT$(NC)]      Running tests..."
	@$(CC) tests/program.c -Lbuild -lft -lbsd -o test.bin
	./test.bin

.PHONY: all clean fclean re