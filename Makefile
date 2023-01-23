NAME = fractol
FILE = fractol \
		ft_initialise \
		ft_key_press \
		ft_mandelbrot \
		ft_burning_ship \
		ft_my_burning_ship \
		ft_julia \
		ft_atof \
		utils \
		ft_colors \
		ft_zoom \
		ft_exit\
		ft_fractal \
		ft_gradient
SRCS = $(addprefix SRCS/, $(addsuffix .c, $(FILE)))
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3 -Imlx

# ^^^^^^^^^^^^^ INCLUDING MINILIBX ^^^^^^^^^^^^^
MLX_DIR = minilibx
MLX_PATH = ${MLX_DIR}/libmlx.a
MLX = -framework OpenGl -framework AppKit $(MLX_PATH)

# ^^^^^^^^^^^^^ INCLUDING MATH.H ^^^^^^^^^^^^^^^
MATH = -lm

# ^^^^^^^^^^^^^ RULING AND STUFF ^^^^^^^^^^^^^^^
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX) $(MATH)

clean:
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re