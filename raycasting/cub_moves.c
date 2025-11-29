/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:59:00 by lhchiban          #+#    #+#             */
/*   Updated: 2025/11/29 11:45:42 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	move_player(t_cub3d *data, double new_dirx, double new_diry)
{
	double	new_x;
	double	new_y;
	double	new_xmargin;
	double	new_ymargin;

	new_x = new_dirx + data->player.pos_x;
	if (new_dirx > 0)
		new_xmargin = 0.2;
	else
		new_xmargin = -0.2;
	if (!is_wall(data, new_x + new_xmargin, data->player.pos_y))
		data->player.pos_x = new_x;
	new_y = new_diry + data->player.pos_y;
	if (new_diry > 0)
		new_ymargin = 0.2;
	else
		new_ymargin = -0.2;
	if (!is_wall(data, data->player.pos_x, new_y + new_ymargin))
		data->player.pos_y = new_y;
	raycasting(&data->player, data);
}

void	move_right(t_cub3d *data)
{
	double	new_dirx;
	double	new_diry;

	if (MOVESPEED > 0.79)
	{
		new_dirx = -data->player.dir_y * 0.79;
		new_diry = data->player.dir_x * 0.79;
	}
	else
	{
		new_dirx = -data->player.dir_y * MOVESPEED;
		new_diry = data->player.dir_x * MOVESPEED;
	}
	move_player(data, new_dirx, new_diry);
}

void	move_left(t_cub3d *data)
{
	double	new_dirx;
	double	new_diry;

	if (MOVESPEED > 0.79)
	{
		new_dirx = data->player.dir_y * 0.79;
		new_diry = -data->player.dir_x * 0.79;
	}
	else
	{
		new_dirx = data->player.dir_y * MOVESPEED;
		new_diry = -data->player.dir_x * MOVESPEED;
	}
	move_player(data, new_dirx, new_diry);
}

void	move_forward(t_cub3d *data)
{
	double	new_dirx;
	double	new_diry;

	if (MOVESPEED > 0.79)
	{
		new_dirx = data->player.dir_x * 0.79;
		new_diry = data->player.dir_y * 0.79;
	}
	else
	{
		new_dirx = data->player.dir_x * MOVESPEED;
		new_diry = data->player.dir_y * MOVESPEED;
	}
	move_player(data, new_dirx, new_diry);
}

void	move_backward(t_cub3d *data)
{
	double	new_dirx;
	double	new_diry;

	if (MOVESPEED > 0.79)
	{
		new_dirx = -data->player.dir_x * 0.79;
		new_diry = -data->player.dir_y * 0.79;
	}
	else
	{
		new_dirx = -data->player.dir_x * MOVESPEED;
		new_diry = -data->player.dir_y * MOVESPEED;
	}
	move_player(data, new_dirx, new_diry);
}
