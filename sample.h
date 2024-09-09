NAME = fdf
#Directories
	SRCS_DIR = source INCLUDES_DIR = includes LIBFTPFGNL_DIR = libft_pf_gnl MLX_DIR = mlx_linux
#SourceandObjectfiles
		SRCS = 0_main.c 1_init.c 2_map_.c 2_map_util.c 3_offset_zoom_.c 3_offset_zoom_util.c 4_drawing.c 5_colors.c 6_slopes_a.c 6_slopes_b.c 7_key.c 8_panel.c 9_close.c SRCS_PATHS = $(addprefix $(SRCS_DIR)
				/, $(SRCS)) OBJS = $(SRCS_PATHS
																																																									:.c =.o)
#LibrariesandHeaders

			LIBFTPFGNL = $(LIBFTPFGNL_DIR)
				/ libft_pf_gnl.a LIBFTPFGNL_HEADERS = $(LIBFTPFGNL_DIR)
				/ includes HEADERS = -I$(INCLUDES_DIR) - I$(LIBFTPFGNL_HEADERS)
				- I$(MLX_DIR) MLX = $(MLX_DIR) /
	libmlx.a
#Compiler and Flags - fsanitize = address
		CC = cc CFLAGS = -Wall - Wextra - Werror - g LDFLAGS = -L$(MLX_DIR)
			- lmlx - L / usr / lib - lXext - lX11 - lm -
		lz
#Targets
			all : $(NAME) $(NAME)
	: $(OBJS) $(LIBFTPFGNL) $(MLX) $(CC) $(CFLAGS) $(OBJS) $(LIBFTPFGNL) $(LDFLAGS)
		- o $(NAME) $(SRCS_DIR) / %.o : $(SRCS_DIR) /
		%.c $(CC) $(CFLAGS) $(HEADERS) - c $ <
	-o $ @$(LIBFTPFGNL) : $(MAKE) - C $(LIBFTPFGNL_DIR) $(MLX) : $(MAKE)
		- C $(MLX_DIR) clean : $(RM) $(OBJS) $(MAKE) clean
		- C $(LIBFTPFGNL_DIR) $(MAKE) clean
		- C $(MLX_DIR) fclean : clean $(RM) $(NAME) $(MAKE) fclean
		- C $(LIBFTPFGNL_DIR) re : fclean all.PHONY : all clean fclean re