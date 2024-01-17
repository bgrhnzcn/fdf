INCLUDES_LINUX = -I/usr/include -Imlx -ILibft -Iget_next_line -Ift_printf

INCLUDES_MAC = -ILibft -Iget_next_line -Ift_printf

NAME = fdf

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

MLX_FLAGS_LINUX = ft_printf/libftprintf.a get_next_line/get_next_line.a Libft/libft.a libmlx.a\
			-Bdynamic -L/usr/lib/X11 -lXext -lX11 -lm

MLX_FLAGS_MAC = Libft/libft.a get_next_line/get_next_line.a ft_printf/libftprintf.a mac_lib/libmlx.a -Bdynamic -framework OpenGL -framework AppKit

SRCS = main.c input.c inits.c transforms.c \
	utils_bresenham_line.c utils_display.c fdf_map.c \
	gradient_line.c pipeline.c errors.c draw_map.c

ifeq ($(shell uname),Linux)
	MLX_FLAGS = $(MLX_FLAGS_LINUX)
	INCLUDES = $(INCLUDES_LINUX)
else
	MLX_FLAGS = $(MLX_FLAGS_MAC)
	INCLUDES = $(INCLUDES_MAC)
endif

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $(INCLUDES) $?

$(NAME): libs $(OBJ) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

all: $(NAME)

libs:
	cd Libft && make
	cd ft_printf && make
	cd get_next_line && make

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf *.o
	cd Libft && make fclean
	cd ft_printf && make fclean
	cd get_next_line && make fclean

re: fclean all
