SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c  ft_split.c  ft_strmapi.c ft_putnbr_fd.c\
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_strtrim.c ft_itoa.c mtx3_basic.c mtx4_basic.c colors.c projections.c transforms.c \
	utils.c utils_display.c utils_maps.c utils_bresenham_line.c vec_conv.c vec2_double.c \
	vec2_op.c vec2_vec2.c vec3_double.c vec3_vec3.c vec3_op.c vec4_double.c vec4_op.c \
	vec4_vec4.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_arrays.c

OBJECTS = $(SRCS:.c=.o)

BONUS_OBJECTS = $(BONUS_SRCS:.c=.o)

CC = gcc

FLAGS = -g -Wall -Werror -Wextra

NAME = libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $?

$(NAME): ${OBJECTS} 
	ar -rcs $(NAME) $(OBJECTS)

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	ar -rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean