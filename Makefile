NAME = main

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INCLUDES = -Iinclude
GLFELINK = -lglfw
FRAMEWOKS = -framework Cocoa -framework OpenGL -framework IOKit

SRC = main.c cub_utils1.c cub_img.c cub_moves.c cub_rotate.c
OBJ = $(SRC:.c=.o)
MLXLIB = MLX42/build/libmlx42.a

all : $(NAME)

%.o: %.c cub.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXLIB) $(INCLUDES) $(GLFELINK) $(FRAMEWOKS) -o $(NAME)

clean :
	$(RM) $(OBJ) $(NAME)

fclean :
	$(RM) $(OBJ)

re : fclean all

.PHONY: clean
