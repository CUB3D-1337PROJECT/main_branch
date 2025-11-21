# // slakhrou
CC = cc	-fsanitize=address
# CFLAGS = -Wall -Wextra -Werror -I$(MLX_DIR) -I$(GLFW_DIR)/include
# MLX_DIR = /home/slakhrou/Desktop/MLX42/build
# GLFW_DIR = /home/slakhrou/Desktop/MLX42/glfw
# MLXF = -L$(MLX_DIR) -lmlx42 -L$(GLFW_DIR)/build/src -lglfw3 -lX11 -lXext -lm

# RM = rm -rf
# NAME = cub3D

# //reflix
# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# MLX_DIR = ./MLX42
# MLXF = -I$(MLX_DIR)/include \
# 		-L$(MLX_DIR)/build -lmlx42\
# 		-L/goinfre/lhchiban/homebrew/lib -lglfw3 \
# 		-framework Cocoa -framework OpenGL -framework IOKit
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ./MLX42
MLXF = -I$(MLX_DIR)/include \
		-L$(MLX_DIR)/build -lmlx42 \
		-L$(MLX_DIR)/build/_deps/glfw-build/src -lglfw \
		-ldl -pthread -lm -lX11

# 		-framework Cocoa -framework OpenGL -framework IOKit

# -ldl -pthread -lm -lX11

RM = rm -rf
NAME
# // maiin
SRC =	main.c	\
		get_next_line/get_next_line.c	outils.c	functions.c\
		parsing/parser.c	parsing/printing.c	parsing/parsing_map.c\
		parsing/parsing_textures.c	parsing/hepler_functions.c\
    parsing/colors_texture.c parsing/map_functions.c	parsing/foutils.c\
    raycasting/clean.c raycasting/cub_img.c raycasting/cub_moves.c\
    raycasting/cub_rotate.c raycasting/cub_utils1.c raycasting/dda_algo.c\
		ft_split.c	ft_atoi.c

OBJ = $(SRC:.c=.o)

# // slakhrou
# all:$(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) $(MLXF) -o $(NAME)

# %.o: %.c cub3d.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(GLFW_DIR)/build/src/libglfw3.a:
# 	cmake -S $(GLFW_DIR) -B $(GLFW_DIR)/build
# 	cmake --build $(GLFW_DIR)/build

# $(MLX_DIR)/libmlx42.a:
# 	cmake -B $(MLX_DIR) -S	/home/slakhrou/Desktop/MLX42
# 	cmake -C	$(MLX_DIR)

# clean:
# 	$(RM) $(OBJ)

# fclean: clean
# 	$(RM) $(NAME)

# re: fclean all
# // reflix
all : $(NAME)


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


# all : $(NAME)

# $(NAME) : $(OBJ)
# 	$(CC)	$(CFLAGS)	$(OBJ)	$(MLXF)	-o $(NAME)

# %.o : %.c	cub3d.h
# 	$(CC)	$(CFLAGS)	-c	$< -o $@

# clean :
# 	$(RM)	$(OBJ)

# fclean : clean
# 	$(RM)	$(NAME)
# re : fclean	all
# # // main

