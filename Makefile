EXECUTABLE_NAME = libft.a

COMPILER = cc
# CFLAGS = -Wall -Wextra -Werror -lbsd
CFLAGS = -lbsd

OBJ_DIR = binarys

SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(EXECUTABLE_NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(EXECUTABLE_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -r $(EXECUTABLE_NAME)

re: fclean
	make

.PHONY: all clean fclean re