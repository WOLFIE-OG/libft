# Define colors
YELLOW=\033[1;33m
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror
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
	ft_binary.c

OBJS = $(SRCS:%.c=obj/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=obj/%.o)
MISC_OBJS = $(MISC_SRCS:%.c=obj/%.o)
FT_PRINTF_DIR = $(MODULES)/ft_printf
GNL_DIR = $(MODULES)/ft_get_next_line
FT_PRINTF_OBJS = $(wildcard $(FT_PRINTF_DIR)/obj/*.o)
GNL_OBJS = $(wildcard $(GNL_DIR)/obj/*.o)
AR_COMMAND = ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS) $(MISC_OBJS)

all: dir $(NAME)

dir:
	@echo "$(GREEN)[LIBFT]     Creating obj directory...$(NC)"
	@mkdir -p obj
	@echo "$(GREEN)[LIBFT]     Creating build directory...$(NC)"
	@mkdir -p build

obj/%.o: src/%.c
	@echo "$(GREEN)[LIBFT]     Compiling $< --> $@$(NC)"
	@$(CC) -o $@ -c $< $(CFLAGS)

check_modules:
	@if [ ! -d "$(FT_PRINTF_DIR)" ]; then \
		echo "$(YELLOW)[LIBFT]     Warning: ft_printf module directory does not exist. Skipping its inclusion.$(NC)"; \
	elif [ -z "$(wildcard $(FT_PRINTF_DIR)/include/*.h)" ]; then \
		echo "$(YELLOW)[LIBFT]     Warning: ft_printf module directory exists but is empty. Skipping its inclusion.$(NC)"; \
	else \
		$(MAKE) -s -C $(FT_PRINTF_DIR); \
	fi
	@if [ ! -d "$(GNL_DIR)" ]; then \
		echo "$(YELLOW)[LIBFT]     Warning: ft_get_next_line module directory does not exist. Skipping its inclusion.$(NC)"; \
	elif [ -z "$(wildcard $(GNL_DIR)/include/*.h)" ]; then \
		echo "$(YELLOW)[LIBFT]     Warning: ft_get_next_line module directory exists but is empty. Skipping its inclusion.$(NC)"; \
	else \
		$(MAKE) -s -C $(GNL_DIR); \
	fi

$(NAME): $(OBJS) $(BONUS_OBJS) $(MISC_OBJS) check_modules
	@echo "$(GREEN)[LIBFT]     Creating $(NAME)...$(NC)"
	@if [ -d "$(FT_PRINTF_DIR)" ] && [ ! -z "$(wildcard $(FT_PRINTF_DIR)/obj/*.o)" ]; then \
		echo "$(GREEN)[LIBFT]     Adding ft_printf module to $(NAME)...$(NC)"; \
		$(AR_COMMAND) $(FT_PRINTF_OBJS); \
	fi
	@if [ -d "$(GNL_DIR)" ] && [ ! -z "$(wildcard $(GNL_DIR)/obj/*.o)" ]; then \
		echo "$(GREEN)[LIBFT]     Adding ft_get_next_line module to $(NAME)...$(NC)"; \
		$(AR_COMMAND) $(GNL_OBJS); \
	fi
	@$(AR_COMMAND)
	@mv $(NAME) build/

check_modules_clean:
	@if [ -d "$(FT_PRINTF_DIR)" ]; then \
		if [ ! -z "$(wildcard $(FT_PRINTF_DIR)/include/*.h)" ]; then \
			echo "$(YELLOW)[LIBFT]     Cleaning ft_printf module.$(NC)"; \
			$(MAKE) -s -C $(FT_PRINTF_DIR) clean; \
		else \
			echo "$(RED)[LIBFT]     ft_printf module is not clean, skipping cleaning.$(NC)"; \
		fi \
	else \
		echo "$(YELLOW)[LIBFT]     Warning: ft_printf module directory does not exist. Skipping cleaning.$(NC)"; \
	fi
	@if [ -d "$(GNL_DIR)" ]; then \
		if [ ! -z "$(wildcard $(GNL_DIR)/include/*.h)" ]; then \
			echo "$(YELLOW)[LIBFT]     Cleaning ft_get_next_line module.$(NC)"; \
			$(MAKE) -s -C $(GNL_DIR) clean; \
		else \
			echo "$(RED)[LIBFT]     ft_get_next_line module is not clean, skipping cleaning.$(NC)"; \
		fi \
	else \
		echo "$(YELLOW)[LIBFT]     Warning: ft_get_next_line module directory does not exist. Skipping cleaning.$(NC)"; \
	fi

clean: check_modules_clean
	@echo "$(YELLOW)[LIBFT]     Cleaning object files...$(NC)"
	@rm -rf $(OBJS) $(BONUS_OBJS) $(MISC_OBJS)
	@rm -rf obj

fclean: clean
	@echo "$(YELLOW)[LIBFT]     Cleaning build directory...$(NC)"
	@rm -rf build/$(NAME)
	@rm -rf build

re: fclean all

test: all
	@echo "$(GREEN)[LIBFT]     Adding test...$(NC)"
	@mkdir -p tests/
	@wget https://gist.githubusercontent.com/WOLFIE-OG/5fe84b7e6f5ba7b7dc0ed503c6504d78/raw/27fff2ca0ea82c5e63b32bbfa499081b15330d84/ANSI-color-codes.h -O tests/ANSI-color-codes.h
	@wget https://gist.githubusercontent.com/WOLFIE-OG/5fe84b7e6f5ba7b7dc0ed503c6504d78/raw/27fff2ca0ea82c5e63b32bbfa499081b15330d84/program.c -O tests/program.c
	@echo "$(GREEN)[LIBFT]     Running tests...$(NC)"
	@$(CC) tests/program.c tests/ANSI-color-codes.h -Lbuild -lft -lbsd -o test.bin
	./test.bin
	rm test.bin
	rm -rf tests
	@echo "$(YELLOW)[LIBFT]     Removing test...$(NC)"
	@rm -rf tests/