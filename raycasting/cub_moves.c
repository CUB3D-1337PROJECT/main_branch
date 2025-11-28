/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:59:00 by lhchiban          #+#    #+#             */
/*   Updated: 2025/11/28 15:56:41 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int is_wall(t_cub3d *data, double x, double y)
{
    if (x < 0 || y < 0 || y >= data->map_length || x >= data->map_width)
        return (1);
    if (data->map[(int)y][(int)x] == '1')
        return (1);
    return (0);
}

void move_right(t_cub3d *data)
{
	if (!is_wall(data,  data->player.pos_x - data->player.dir_y * MOVESPEED,
			data->player.pos_y + data->player.dir_x * MOVESPEED))
	{
		data->player.pos_y = data->player.pos_y + data->player.dir_x * MOVESPEED;
		data->player.pos_x = data->player.pos_x - data->player.dir_y * MOVESPEED;
	}
	raycasting(&data->player, data);
}

void move_left(t_cub3d *data)
{
	if (!is_wall(data, data->player.pos_x + data->player.dir_y * MOVESPEED,
			data->player.pos_y - data->player.dir_x * MOVESPEED))
	{
		data->player.pos_y = data->player.pos_y - data->player.dir_x * MOVESPEED;
		data->player.pos_x = data->player.pos_x + data->player.dir_y * MOVESPEED;
	}
	raycasting(&data->player, data);
}
void move_forward(t_cub3d *data)
{
	if (!is_wall(data, data->player.pos_x + data->player.dir_x * MOVESPEED,
        data->player.pos_y + data->player.dir_y * MOVESPEED))
    {
        data->player.pos_x = data->player.pos_x + data->player.dir_x * MOVESPEED;
		data->player.pos_y = data->player.pos_y + data->player.dir_y * MOVESPEED;
	}
	raycasting(&data->player, data);
}

void move_backward(t_cub3d *data)
{
	if (!is_wall(data, data->player.pos_x - data->player.dir_x * MOVESPEED,
	 	data->player.pos_y - data->player.dir_y * MOVESPEED))
	{
		data->player.pos_y = data->player.pos_y - data->player.dir_y * MOVESPEED;
		data->player.pos_x = data->player.pos_x - data->player.dir_x * MOVESPEED;
	}
	raycasting(&data->player, data);
}
