CC = cc	#-fsanitize=address
CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR) -I$(GLFW_DIR)/include
MLX_DIR = /home/slakhrou/Desktop/MLX42/build
GLFW_DIR = /home/slakhrou/Desktop/MLX42/glfw
MLXF = -L$(MLX_DIR) -lmlx42 -L$(GLFW_DIR)/build/src -lglfw3 -lX11 -lXext -lm

RM = rm -rf
NAME = cub3D

SRC =	main.c	\
		get_next_line/get_next_line.c	outils.c	functions.c\
		parsing/parser.c	parsing/printing.c	parsing/parsing_map.c\
		parsing/parsing_textures.c	parsing/hepler_functions.c\
		parsing/map_functions.c	parsing/foutils.c	parsing/colors_texture.c\
		ft_split.c	ft_atoi.c

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXF) -o $(NAME)

%.o: %.c cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

$(GLFW_DIR)/build/src/libglfw3.a:
	cmake -S $(GLFW_DIR) -B $(GLFW_DIR)/build
	cmake --build $(GLFW_DIR)/build

$(MLX_DIR)/libmlx42.a:
	cmake -B $(MLX_DIR) -S	/home/slakhrou/Desktop/MLX42
	cmake -C	$(MLX_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
