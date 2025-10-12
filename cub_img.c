/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:12:21 by lhchiban          #+#    #+#             */
/*   Updated: 2025/10/08 05:44:25 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void cub_create_pimg(cub_data_t *data)
{
	int p_x;
	int p_y;
	double endX;
	double endY;
	double x_inc;
	double y_inc;
	int i = -1;
	if (data->player_rid == 'E')
	{
		data->dirX = 1;
		data->dirY = 0;
	}
	if (data->player_rid == 'W')
	{
		data->dirX = -1;
		data->dirY = 0;
	}
	if (data->player_rid == 'S')
	{
		data->dirX = 0;
		data->dirY = 1;
	}
	if (data->player_rid == 'N')
	{
		data->dirX = 0;
		data->dirY = -1;
	}
	endX = data->player_x + data->dirX * BLOCK_SIZE;
	endY = data->player_y + data->dirY * BLOCK_SIZE;
	double steps;
	if (fabs(endX - data->player_x) > fabs(endY - data->player_y))
		steps = fabs(endX - data->player_x);
	else
		steps = fabs(endY - data->player_y);
	x_inc = (endX - data->player_x)/steps;
	y_inc = (endY - data->player_y)/steps;
	mlx_delete_image(data->mlx, data->player_img);
	mlx_delete_image(data->mlx, data->playerv_img);
	data->player_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->playerv_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	p_x = 0;
	p_y = 0;
	while (p_x < 16)
	{
		p_y = 0;
		while (p_y < 16)
		{
			mlx_put_pixel(data->playerv_img, p_x , p_y, 0xffffff);
			p_y++;
		}
		p_x++;
	}
	mlx_image_to_window(data->mlx, data->playerv_img, data->player_x, data->player_y);
	p_x = data->player_x;
	p_y = data->player_y;
	while (++i < steps)
	{
		mlx_put_pixel(data->player_img, p_x +7, p_y +7, 0xff00ff);
		p_x += x_inc;
		p_y += y_inc;
	}
}

void cub_creat_pvimg(cub_data_t *data)
{
	mlx_image_to_window(data->mlx, data->player_img, 0, 0);
}

static void cub_set_texture(cub_data_t *data, int j, int i)
{
	data->tex = mlx_load_png
		("/mnt/homes/lhchiban/Desktop/text/Wall_cobblestone_cracks_32px.png");
	data->img_tex = mlx_texture_to_image(data->mlx, data->tex);
	mlx_image_to_window(data->mlx, data->img_tex, j * (32), i * (32));
}

void cub_draw_map(cub_data_t *data)
{
	char **d_map;
	int i;
	int j;

	d_map = data->map;
	i = -1;
	while (d_map[++i])
	{
		j = -1;
		while(d_map[i][++j])
		{
			if (d_map[i][j] == '1')
				cub_set_texture(data, j, i);
			 if (d_map[i][j] == 'N' || d_map[i][j] == 'E'
					|| d_map[i][j] == 'W' || d_map[i][j] == 'S')
			{
				data->player_x = BLOCK_SIZE * j;
				data->player_y = BLOCK_SIZE * i;
				data->player_rid = d_map[i][j];
				cub_create_pimg(data);
				cub_creat_pvimg(data);
			}
		}
	}
}
