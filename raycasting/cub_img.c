/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:12:21 by lhchiban          #+#    #+#             */
/*   Updated: 2025/11/11 16:18:44 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void init_raycasting(t_rayinfo *ray, int x, t_playerinfo *player)
{
	ray->camera_x = 2 * x/(double)WIDTH -1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x ;
	ray->map_y = (int)player->pos_y;
	ray->dest_x = fabs(1 / ray->dir_x);
	ray->dest_y = fabs(1 / ray->dir_y);
}

static void	set_dda(t_rayinfo *ray, t_playerinfo *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->dest_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->dest_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->dest_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->dest_y;
	}
}

static void	perform_dda(t_cub3d *data, t_rayinfo *ray)
{
	int	hit;
	(void)data;
	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->dest_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->dest_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0 || ray->map_x < 0 ||
			ray->map_y >= data->map_length
			|| ray->map_x >= data->map_width)
			break;
		else if (data->map[(int)ray->map_y][(int)ray->map_x] == '1')
			hit = 1;

	}
}

static void	calculate_line_height(t_rayinfo *ray, t_cub3d *data, t_playerinfo *player)
{
	(void)data;
	if (ray->side == 0)
		ray->wall_dest = (ray->sidedist_x - ray->dest_x);
	else
		ray->wall_dest = (ray->sidedist_y - ray->dest_y);
	ray->line_h = (int)(HEIGHT / ray->wall_dest);
	ray->start_draw = -(ray->line_h) / 2 + HEIGHT / 2;
	if (ray->start_draw < 0)
		ray->start_draw = 0;
	ray->draw_end = ray->line_h / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dest * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dest * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

static void	init_ray(t_rayinfo *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->dest_x = 0;
	ray->dest_y = 0;
	ray->wall_dest = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_h = 0;
	ray->start_draw = 0;
	ray->draw_end = 0;
}

// void raycasting(t_playerinfo *player, t_cub3d *data)
// {
// 	int x;

// 	x = 0;
// 	init_ray(&data->ray);

// 	while (x < WIDTH)
// 	{
// 		init_raycasting(&data->ray, x, player);
// 		set_dda(&data->ray, player);
// 		perform_dda(data, &data->ray);
// 		calculate_line_height(&data->ray, data, player);
// 		int y = data->ray.start_draw;
// 		while (y < data->ray.draw_end)
// 		{
// 			uint32_t color; // temporary white walls

// 			if (data->ray.side == 0)
// 				color = 0xFF0000FF; // red walls (vertical)
// 			else
// 				color = 0x00FF00FF; // green walls (horizontal)
// 			mlx_(data->img, x, y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }

void raycasting(t_playerinfo *player, t_cub3d *data)
{
    int x;
    int y;
    uint32_t *pixel_buffer;
	pixel_buffer = (uint32_t *)data->img->pixels;
    if (!pixel_buffer || data->img->width != WIDTH || data->img->height != HEIGHT)
        return;

    x = 0;
    init_ray(&data->ray);

    while (x < WIDTH)
    {
        init_raycasting(&data->ray, x, player);
        set_dda(&data->ray, player);
        perform_dda(data, &data->ray);
        calculate_line_height(&data->ray, data, player);
        y = 0;
        while (y < HEIGHT)
        {
            uint32_t color;
            if (y < data->ray.start_draw)
                color = data->rgb_color_ceiling;
            else if (y >= data->ray.draw_end)
                color = data->rgb_color_flour;
            else
            {
                if (data->ray.side == 0)
                    color = 0xFFFFFFF0;
                else
                    color = 0xFFFFFF0F;
            }
            pixel_buffer[y * WIDTH + x] = color;

            y++;
        }
        x++;
    }
	// mlx_image_to_window(data->mlx, data->img, 0, 0);
}
