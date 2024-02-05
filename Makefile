# Define colors
YELLOW=\033[1;33m
RED=\033[1;31m
GREEN=\033[1;32m
BLUE=\033[0;34m
NC=\033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libft.a
MODULES = src/modules
SRCS = ft_isalpha.c \
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
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstsize.c

MISC_SRCS = ft_abs.c \
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
	ft_binary.c \
	ft_free_char_array.c

OBJS = $(SRCS:%.c=obj/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=obj/%.o)
MISC_OBJS = $(MISC_SRCS:%.c=obj/%.o)
FT_PRINTF_DIR = $(MODULES)/ft_printf
GNL_DIR = $(MODULES)/ft_get_next_line
FT_PRINTF_OBJS = $(wildcard $(FT_PRINTF_DIR)/obj/*.o)
GNL_OBJS = $(wildcard $(GNL_DIR)/obj/*.o)
AR_COMMAND = ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS) $(MISC_OBJS)
BUILD_DIR = build

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

obj/%.o: src/%.c
	@echo "[$(GREEN)LIBFT$(NC)]     Compiling $< --> $@"
	@$(CC) -o $@ -c $< $(CFLAGS)

check_modules:
	@if [ ! -d "$(FT_PRINTF_DIR)" ]; then \
		echo "[$(YELLOW)LIBFT$(NC)]     Warning: ft_printf module directory does not exist. Skipping its inclusion."; \
	elif [ -z "$(wildcard $(FT_PRINTF_DIR)/include/*.h)" ]; then \
		echo "[$(YELLOW)LIBFT$(NC)]     Warning: ft_printf module directory exists but is empty. Skipping its inclusion."; \
	else \
		$(MAKE) -s -C $(FT_PRINTF_DIR); \
	fi
	@if [ ! -d "$(GNL_DIR)" ]; then \
		echo "[$(YELLOW)LIBFT$(NC)]     Warning: ft_get_next_line module directory does not exist. Skipping its inclusion."; \
	elif [ -z "$(wildcard $(GNL_DIR)/include/*.h)" ]; then \
		echo "[$(YELLOW)LIBFT$(NC)]     Warning: ft_get_next_line module directory exists but is empty. Skipping its inclusion."; \
	else \
		$(MAKE) -s -C $(GNL_DIR); \
	fi

$(NAME): $(OBJS) $(BONUS_OBJS) $(MISC_OBJS) check_modules
	@echo "[$(GREEN)LIBFT$(NC)]     Creating $(NAME)..."
	@if [ -d "$(FT_PRINTF_DIR)" ] && [ ! -z "$(wildcard $(FT_PRINTF_DIR)/obj/*.o)" ]; then \
		echo "[$(GREEN)LIBFT$(NC)]     Adding ft_printf module to $(NAME)..."; \
		$(AR_COMMAND) $(FT_PRINTF_OBJS); \
	fi
	@if [ -d "$(GNL_DIR)" ] && [ ! -z "$(wildcard $(GNL_DIR)/obj/*.o)" ]; then \
		echo "[$(GREEN)LIBFT$(NC)]     Adding ft_get_next_line module to $(NAME)..."; \
		$(AR_COMMAND) $(GNL_OBJS); \
	fi
	@$(AR_COMMAND)
	@mv $(NAME) $(BUILD_DIR)/

check_modules_clean:
	@if [ -d "$(FT_PRINTF_DIR)" ]; then \
		if [ ! -z "$(wildcard $(FT_PRINTF_DIR)/include/*.h)" ]; then \
			echo "[$(BLUE)LIBFT$(NC)]     Cleaning ft_printf module."; \
			$(MAKE) -s -C $(FT_PRINTF_DIR) clean; \
		else \
			echo "[$(RED)LIBFT$(NC)]     ft_printf module is not clean, skipping cleaning."; \
		fi \
	else \
		echo "[$(YELLOW)LIBFT$(NC)]     Warning: ft_printf module directory does not exist. Skipping cleaning."; \
	fi
	@if [ -d "$(GNL_DIR)" ]; then \
		if [ ! -z "$(wildcard $(GNL_DIR)/include/*.h)" ]; then \
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
	@echo "[$(YELLOW)LIBFT$(NC)]     Cleaning build directory..."
	@rm -rf $(BUILD_DIR)/$(NAME)
	@rm -rf $(BUILD_DIR)

re: fclean all

test: all
	@echo "[$(GREEN)LIBFT$(NC)]      Adding test..."
	@echo "[$(GREEN)LIBFT$(NC)]      Running tests..."
	@$(CC) tests/program.c tests/ANSI-color-codes.h -Lbuild -lft -lbsd -o test.bin
	./test.bin