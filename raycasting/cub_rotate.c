/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:49:27 by lhchiban          #+#    #+#             */
/*   Updated: 2025/11/28 00:16:51 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void rotate_right(t_cub3d *data, t_rotateinfo rotate)
{
	rotate.rotate_planx = data->player.plane_x;
	rotate.rotate_dirx = data->player.dir_x;
	data->player.dir_x  = rotate.rotate_dirx * cos(ROTATE_R) - data->player.dir_y * sin(ROTATE_R);
	data->player.dir_y  = data->player.dir_y * cos(ROTATE_R) + rotate.rotate_dirx * sin(ROTATE_R);
	data->player.plane_x  = rotate.rotate_planx * cos(ROTATE_R) - data->player.plane_y * sin(ROTATE_R);
	data->player.plane_y  = data->player.plane_y * cos(ROTATE_R) + rotate.rotate_planx * sin(ROTATE_R);
	raycasting(&data->player, data);
}

void rotate_left(t_cub3d *data, t_rotateinfo rotate)
{
	rotate.rotate_planx = data->player.plane_x;
	rotate.rotate_dirx = data->player.dir_x;
	data->player.dir_x  = rotate.rotate_dirx * cos(ROTATE_L) - data->player.dir_y * sin(ROTATE_L);
	data->player.dir_y  = data->player.dir_y * cos(ROTATE_L) + rotate.rotate_dirx * sin(ROTATE_L);
	data->player.plane_x  = rotate.rotate_planx * cos(ROTATE_L) - data->player.plane_y * sin(ROTATE_L);
	data->player.plane_y  = data->player.plane_y * cos(ROTATE_L) + rotate.rotate_planx * sin(ROTATE_L);
	raycasting(&data->player, data);
}
