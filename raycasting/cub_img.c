/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:12:21 by lhchiban          #+#    #+#             */
/*   Updated: 2025/11/20 22:35:29 by shepani-hash     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void init_raycasting(t_rayinfo *ray, int x, t_playerinfo *player)
{
    ray->camera_x = 2 * x/(double)WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->raystart_x = player->pos_x;
	ray->raystart_y = player->pos_y;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
    if (ray->dir_x == 0)
        ray->dest_x = INFINITY;
    else
        ray->dest_x = fabs(1.0 / ray->dir_x);
    if (ray->dir_y == 0)
        ray->dest_y = INFINITY;
    else
        ray->dest_y = fabs(1.0 / ray->dir_y);
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
    ray->tex_x = 0;
    ray->tex_y = 0;
    ray->tex_step = 0;
    ray->tex_pos = 0;
}

static void texture_sides(t_cub3d *data)
{
    if (data->ray.side == 1)
    {
        if (data->ray.dir_y > 0)
            data->curr_texture = data->texts->text_so; 
       else
            data->curr_texture = data->texts->text_no; 
    }
    else
    {
        if (data->ray.dir_x > 0)
            data->curr_texture = data->texts->text_ea; 
        else
            data->curr_texture = data->texts->text_we; 
    }
}

static void	sample_texture(t_texture_colors *tc, t_cub3d *data)
{
        tc->tex_y = (int)(data->ray.tex_pos);
        if (tc->tex_y < 0)
            tc->tex_y = 0;
        if (tc->tex_y >= (int)data->curr_texture->height)
            tc->tex_y = (int)data->curr_texture->height - 1;
        tc->tex_x = data->ray.tex_x;
        if (tc->tex_x < 0) 
            tc->tex_x = 0;
        if (tc->tex_x >= (int)data->curr_texture->width)
            tc->tex_x = (int)data->curr_texture->width - 1;
        tc->color = ((uint32_t *)data->curr_texture->pixels)[tc->tex_y * data->curr_texture->width + tc->tex_x];
        data->ray.tex_pos += data->ray.tex_step;
}

static void	calculate_line_height(t_rayinfo *ray, t_cub3d *data, t_playerinfo *player)
{
    if (ray->side == 0)
          ray->wall_dest = (ray->sidedist_x - ray->dest_x);
    else
          ray->wall_dest = (ray->sidedist_y - ray->dest_y);
    // if (ray->side == 0)
    //     ray->wall_dest = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->dir_x;
    // else
    //     ray->wall_dest = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->dir_y;
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
    data->tex_width = data->curr_texture->width;
    data->tex_height = data->curr_texture->height;
    ray->tex_x = (int)(ray->wall_x * (double)data->tex_width);
    if (ray->side == 0 && ray->dir_x > 0)
        ray->tex_x = data->tex_width - ray->tex_x - 1;
    if (ray->side == 1 && ray->dir_y < 0)
        ray->tex_x = data->tex_width - ray->tex_x - 1;
    ray->tex_step = 1.0 * data->tex_height / ray->line_h;
    ray->tex_pos = (ray->start_draw - HEIGHT / 2 + ray->line_h / 2) * ray->tex_step;
}


static void	ft_color(t_cub3d *data, int x, int y)
{
	t_texture_colors	tc;

	tc.pix_buff = (uint32_t *)data->img->pixels;
	if (!tc.pix_buff || data->img->width != WIDTH
		|| data->img->height != HEIGHT)
		ft_clean(data, 0, 0, 0);
	if (y < data->ray.start_draw)
		tc.color = data->rgb_color_ceiling;
	else if (y >= data->ray.draw_end)
		tc.color = data->rgb_color_flour;
	else if (!data->curr_texture || !data->curr_texture->pixels 
            || data->curr_texture->width == 0 || data->curr_texture->height == 0)
		tc.color = 0x00FF00FF;
    else
    {
        sample_texture(&tc, data);
    }
	tc.pix_buff[y * WIDTH + x] = tc.color;
}

void raycasting(t_playerinfo *player, t_cub3d *data)
{
	int x;
	int y;

	x = 0;
	init_ray(&data->ray);
	while (x < WIDTH)
	{
		init_raycasting(&data->ray, x, player);
		set_dda(data);
		texture_sides(data);
		calculate_line_height(&data->ray, data, player);
		y = 0;
		while (y < HEIGHT)
		{
			ft_color(data, x, y);
			y++;
		}
		x++;
	}
}
