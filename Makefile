CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = cub3D
SRC =	main.c	\
		get_next_line/get_next_line.c	outils.c	functions.c\
		parsing/parser.c	parsing/printing.c	parsing/parsing_map.c\
		parsing/parsing_textures.c	\
		ft_split.c

OBJ = $(SRC:.c=.o);

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC)	$(CFLAGS)	$(OBJ) -o $(NAME)

%.o : %.c	cub3d.h
	$(CC)	$(CFLAGS)	$< -o $@

clean :
	$(RM)	$(OBJ)
fclean : clean
	$(RM)	$(NAME)

re : fclean	all


