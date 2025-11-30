CC = cc	-fsanitize=address
RM = rm -rf
NAME = cub3D
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = /mnt/homes/slakhrou/Desktop/MLX42
MLXF = -I$(MLX_DIR)/include \
		-L$(MLX_DIR)/build -lmlx42 \
		-L$(MLX_DIR)/build/_deps/glfw-build/src -lglfw3 \
		-framework Cocoa -framework OpenGL -framework IOKit

SRC =	main.c	\
		get_next_line/get_next_line.c	outils.c	functions.c\
		parsing/parser.c	parsing/printing.c	parsing/parsing_map.c\
		parsing/parsing_textures.c	parsing/hepler_functions.c\
		parsing/colors_texture.c parsing/map_functions.c	parsing/foutils.c\
		raycasting/clean.c raycasting/cub_img.c raycasting/cub_moves.c raycasting/cub_color.c\
		raycasting/cub_rotate.c raycasting/cub_utils1.c raycasting/dda_algo.c\
		ft_split.c	ft_atoi.c	parsing/hepler.c

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXF) -o $(NAME)

%.o: %.c	cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_DIR)/libmlx42.a:
	cmake -B $(MLX_DIR) -S	/home/slakhrou/Desktop/MLX42
	cmake -C	$(MLX_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
