/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spi <spi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:12:21 by lhchiban          #+#    #+#             */
/*   Updated: 2025/10/25 22:04:26 by spi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void init_raycasting(t_rayinfo *ray, int x, t_playerinfo *player)
{
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->camera_x = 0;
	player->dir_x = -1;
	player->dir_y = 0;
	ray->camera_x = 2 * x/(double)WIDTH -1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->pos_x;
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


void raycasting(t_playerinfo *player, t_cub3d *data)
{
	t_rayinfo *ray = &data->ray;
	int x;

	x = 0;
	while (x < WIDTH)
	{
		init_raycasting(ray, x, player);
		set_dda(ray, player);
		perform_dda(data, ray);
		calculate_line_height(ray, data, player);
		int y = ray->start_draw;
		while (y < ray->draw_end)
		{
			uint32_t color; // temporary white walls

			if (ray->side == 0)
				color = 0xFF0000FF; // red walls (vertical)
			else
				color = 0x00FF00FF; // green walls (horizontal)
			mlx_put_pixel(data->img, x, y, color);

			y++;
		}

		x++;
	}
}
