/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spi <spi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:59:00 by lhchiban          #+#    #+#             */
/*   Updated: 2025/11/07 13:30:33 by spi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void move_right(t_cub3d *data)
{
	double 	MOVESPEED;

	MOVESPEED = 0.0125;
	data->player.pos_x = data->player.pos_x - data->player.dir_y * MOVESPEED;
	data->player.pos_y = data->player.pos_y + data->player.dir_x * MOVESPEED;
	raycasting(&data->player, data);
}

void move_left(t_cub3d *data)
{
	double 	MOVESPEED;

	MOVESPEED = 0.0125;
	data->player.pos_x = data->player.pos_x + data->player.dir_y * MOVESPEED;
	data->player.pos_y = data->player.pos_y - data->player.dir_x * MOVESPEED;
	raycasting(&data->player, data);

}
void move_forward(t_cub3d *data)
{
	double 	MOVESPEED;

	MOVESPEED = 0.0125;
	data->player.pos_x = data->player.pos_x + data->player.dir_y * MOVESPEED;
	data->player.pos_y = data->player.pos_y + data->player.dir_x * MOVESPEED;
	raycasting(&data->player, data);
}

void move_backward(t_cub3d *data)
{
	double 	MOVESPEED;

	MOVESPEED = 0.0125;
	data->player.pos_x = data->player.pos_x - data->player.dir_y * MOVESPEED;
	data->player.pos_y = data->player.pos_y - data->player.dir_x * MOVESPEED;
	raycasting(&data->player, data);

}
