# Project Name
NAME = fdf

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# Directories
SRC_DIR = src
MINILIBX_DIR = minilibx-linux
MASTERLIB_DIR = masterLib

# Library files
MASTERLIB = $(MASTERLIB_DIR)/masterLib.a

# Source files and object files
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/parseInput.c $(SRC_DIR)/hooks/hooks.c $(SRC_DIR)/draw.c \
      $(SRC_DIR)/utils.c $(SRC_DIR)/color.c $(SRC_DIR)/rotations.c $(SRC_DIR)/errors.c \
      $(SRC_DIR)/bresenham.c $(SRC_DIR)/project.c $(SRC_DIR)/init_map.c $(SRC_DIR)/init_points.c \
	  $(SRC_DIR)/hooks/init_hooks.c 
OBJ = $(SRC:.c=.o)

# Build the project
all: $(NAME)

# Rule to create the final executable
$(NAME): $(OBJ) $(MASTERLIB)
	@make -C $(MINILIBX_DIR)

	$(CC) $(CFLAGS) $(OBJ) -L$(MINILIBX_DIR) -lmlx -L$(MASTERLIB_DIR) -l:masterLib.a $(MLXFLAGS) -o $(NAME) 

# Rule to ensure the masterLib is compiled
$(MASTERLIB):
	@make -C $(MASTERLIB_DIR)

# Compile object files from source
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)
	@make -C $(MINILIBX_DIR) clean
	@make -C $(MASTERLIB_DIR) clean

# Full clean: remove object files and executable
fclean: clean
	rm -f $(NAME)
	@make -C $(MASTERLIB_DIR) fclean

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re
