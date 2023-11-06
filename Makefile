EXECUTABLE_NAME = libft.a

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -std=c99 -g

OBJ_DIR = bin

SRCS = $(wildcard ft_*.c)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(EXECUTABLE_NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I libft.h -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(EXECUTABLE_NAME): $(OBJS)
	ar rcs $(EXECUTABLE_NAME) $(OBJ_DIR)/*

test:
	clear
	cc program.c libft.a ANSI-color-codes.h -lbsd -g
	./a.out

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -r $(EXECUTABLE_NAME)

re: fclean
	make

.PHONY: all clean fclean re