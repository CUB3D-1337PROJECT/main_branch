CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = cub3D
SRC =	main.c	\
		get_next_line/get_next_line.c	outils.c	functions.c\
		parsing/parser.c	printing.c\
		ft_split.c
OBJ = $(SRC:.c=.o);

all : $(NAME)


