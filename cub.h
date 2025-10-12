# ifndef CUB_H
#define CUB_H

#include "MLX42/include/MLX42/MLX42.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT 14*32
#define WIDTH 33*32
#define BLOCK_SIZE 32

typedef struct cub_data_s
{
    mlx_t *mlx;
    mlx_image_t *img;
    mlx_image_t *player_img;
    mlx_image_t *playerv_img;
    mlx_texture_t *tex;
    mlx_image_t *img_tex;
    double 	player_x;
    double 	player_y;
	double 	planx;
	double 	camerax;
	bool	rotate_f;
	double 	dirX;
	double 	dirY;
	double		tail;
	int		player_rid;
    char	**map;

} cub_data_t;

void cub_handel_events(cub_data_t **data);
void cub_create_pimg(cub_data_t *data);
void cub_creat_pvimg(cub_data_t *data);
void move_right(cub_data_t *data);
void move_left(cub_data_t *data);
void move_forward(cub_data_t *data);
void move_backward(cub_data_t *data);
void rotate_right(cub_data_t *data);
void rotate_left(cub_data_t *data);
char **cub_set_map(void);
void cub_draw_map(cub_data_t *data);
void cub_draw_map2(cub_data_t *data);

#endif
