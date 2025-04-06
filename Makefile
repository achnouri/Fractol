NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -f

MLX = -lmlx
APPKIT = -framework AppKit
OPENGL = -framework OpenGL

SRC = main.c complex.c event.c tools2.c parcing.c fractal.c 
OBJ = $(SRC:.c=.o)


%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) $(APPKIT) $(OPENGL) -o $(NAME)



clean :
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: clean