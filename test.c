#include "MLX42/include/MLX42/MLX42.h"
#include <math.h>
#include "cub.h"

typedef struct s_player {
    double  x;
    double  y;
    double  dirX;
    double  dirY;
	int t;
}   t_player;

void draw_vector(mlx_image_t *img, t_player *p, int scale, uint32_t color)
{
    double endX = p->x + p->dirX * scale;
    double endY = p->y - p->dirY * scale; // minus because Y is inverted in MLX42
    double dx = endX - p->x;
    double dy = endY - p->y;
    double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	printf("%f\n", steps);
    double x_inc = dx / steps;
    double y_inc = dy / steps;
    double x = p->x;
    double y = p->y;

    for (int i = 0; i <= steps; i++)
    {
		mlx_put_pixel(img, (int)x, (int)y, color);
		x += x_inc;
		y += y_inc;
    }
}

int main()
{
	cub_data_t data;
	t_player player = {200,200, 0, 1};
	data.mlx = mlx_init(400, 400, "cubs", false);
	printf("hi\n");
	data.player_img = mlx_new_image(data.mlx, 400, 400);
	draw_vector(data.player_img, &player, 50, 0xFFFF00FF);
	mlx_image_to_window(data.mlx, data.player_img, 0, 0);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}
