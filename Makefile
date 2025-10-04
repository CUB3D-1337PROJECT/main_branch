CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = cub3D
SRC = main.c	\
parsing/.c
OBJ = $(SRC:.c=.o);

all : $(NAME)


