# Directories for each project
FT_PRINTF_DIR = ft_printf
GNL_DIR = get_next_line
LIBFT_DIR = libft

# Header file directories
INCLUDES = -I$(FT_PRINTF_DIR) -I$(GNL_DIR) -I$(LIBFT_DIR)

# Source files for ft_printf project
FT_PRINTF_SRC = $(FT_PRINTF_DIR)/ft_printf.c \
                $(FT_PRINTF_DIR)/ft_putchar.c \
                $(FT_PRINTF_DIR)/ft_putdec.c \
                $(FT_PRINTF_DIR)/ft_puthex.c \
                $(FT_PRINTF_DIR)/ft_putnbr_unsigned.c \
                $(FT_PRINTF_DIR)/ft_putnbr.c \
                $(FT_PRINTF_DIR)/ft_putptr.c \
                $(FT_PRINTF_DIR)/ft_putstr.c \
                $(FT_PRINTF_DIR)/ft_strlen.c

# Source files for get_next_line project
GNL_SRC = $(GNL_DIR)/get_next_line.c \
          $(GNL_DIR)/get_next_line_utils.c

# Source files for libft project
LIBFT_SRC = $(LIBFT_DIR)/ft_atoi.c \
            $(LIBFT_DIR)/ft_bzero.c \
            $(LIBFT_DIR)/ft_calloc.c \
            $(LIBFT_DIR)/ft_isalnum.c \
            $(LIBFT_DIR)/ft_isalpha.c \
            $(LIBFT_DIR)/ft_isascii.c \
            $(LIBFT_DIR)/ft_isdigit.c \
            $(LIBFT_DIR)/ft_isprint.c \
            $(LIBFT_DIR)/ft_itoa.c \
            $(LIBFT_DIR)/ft_lstadd_back.c \
            $(LIBFT_DIR)/ft_lstadd_front.c \
            $(LIBFT_DIR)/ft_lstclear.c \
            $(LIBFT_DIR)/ft_lstdelone.c \
            $(LIBFT_DIR)/ft_lstiter.c \
            $(LIBFT_DIR)/ft_lstlast.c \
            $(LIBFT_DIR)/ft_lstmap.c \
            $(LIBFT_DIR)/ft_lstnew.c \
            $(LIBFT_DIR)/ft_lstsize.c \
            $(LIBFT_DIR)/ft_memchr.c \
            $(LIBFT_DIR)/ft_memcmp.c \
            $(LIBFT_DIR)/ft_memcpy.c \
            $(LIBFT_DIR)/ft_memmove.c \
            $(LIBFT_DIR)/ft_memset.c \
            $(LIBFT_DIR)/ft_putchar_fd.c \
            $(LIBFT_DIR)/ft_putendl_fd.c \
            $(LIBFT_DIR)/ft_putnbr_fd.c \
            $(LIBFT_DIR)/ft_putstr_fd.c \
            $(LIBFT_DIR)/ft_split.c \
            $(LIBFT_DIR)/ft_strchr.c \
            $(LIBFT_DIR)/ft_strdup.c \
            $(LIBFT_DIR)/ft_striteri.c \
            $(LIBFT_DIR)/ft_strjoin.c \
            $(LIBFT_DIR)/ft_strlcat.c \
            $(LIBFT_DIR)/ft_strlcpy.c \
            $(LIBFT_DIR)/ft_strlen.c \
            $(LIBFT_DIR)/ft_strmapi.c \
            $(LIBFT_DIR)/ft_strncmp.c \
            $(LIBFT_DIR)/ft_strnstr.c \
            $(LIBFT_DIR)/ft_strrchr.c \
            $(LIBFT_DIR)/ft_strtrim.c \
            $(LIBFT_DIR)/ft_tolower.c \
            $(LIBFT_DIR)/ft_toupper.c

# All source files combined
SRC = $(FT_PRINTF_SRC) $(GNL_SRC) $(LIBFT_SRC)

# Object files
OBJ = $(SRC:.c=.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

# Library name
LIB_NAME = masterLib.a

# Rule to create the library
all: $(LIB_NAME)

# Archive the object files into a static library
$(LIB_NAME): $(OBJ)
	@ar rcs $(LIB_NAME) $(OBJ)
	@echo "Library $(LIB_NAME) created."

# Compile the object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the library
clean:
	@rm -f $(OBJ)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(LIB_NAME)
	@echo "Library $(LIB_NAME) cleaned."

# Rebuild the library
re: fclean all

.PHONY: all clean fclean re
