#Compiler
CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rcs

#Library name
NAME = libft.a

#Source Files
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
		ft_toupper.c \

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstmap.c\

#Object Files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

#Default Target: Build the library
all: $(NAME)

#Rule to create the library
$(NAME): $(OBJS) 
	$(AR) $(ARFLAGS) $@ $^

#Rule to create bonus files
bonus: $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

#Rule to compile .c files to .o files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ && echo "\033[32m✔\033[0m $< compiled successfully"

#Clean up object files
clean:
	@rm -f $(OBJS) $(BONUS_OBJS) && echo "\033[31m🗑️\033[0m  Object files removed"

#Clean up object files and the library
fclean: clean
	@rm -f $(NAME) && echo "\033[31m🗑️\033[0m  Library removed"

#Rebuild the library
re: fclean all

.PHONY: all clean bonus fclean re