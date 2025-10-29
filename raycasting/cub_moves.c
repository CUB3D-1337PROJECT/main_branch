/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spi <spi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:59:00 by lhchiban          #+#    #+#             */
/*   Updated: 2025/10/16 12:05:04 by spi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void move_right(t_cub3d *data)
{
	data->player_x += 16;
    // raycasting(&data->player, data);
	mlx_delete_image(data->mlx,  data->img);
}

void move_left(t_cub3d *data)
{
	data->player_x -= 16;
	mlx_delete_image(data->mlx,  data->img);

}
void move_forward(t_cub3d *data)
{
	data->player_y -= 16;
	mlx_delete_image(data->mlx,  data->img);
}

void move_backward(t_cub3d *data)
{
	data->player_y += 16;
	mlx_delete_image(data->mlx,  data->img);

}
