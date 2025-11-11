/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:49:27 by lhchiban          #+#    #+#             */
/*   Updated: 2025/11/11 16:33:42 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void rotate_right(t_cub3d *data)
{
	double rotangel;
	rotangel = 0.20;
	double old_plan_x;
	double old_dir_x;
	old_plan_x = data->player.plane_x;
	old_dir_x = data->player.dir_x;
	data->player.dir_x  = old_dir_x * cos(rotangel) - data->player.dir_y * sin(rotangel);
	data->player.dir_y  = data->player.dir_y * cos(rotangel) + old_dir_x * sin(rotangel);
	data->player.plane_x  = old_plan_x * cos(rotangel) - data->player.plane_y * sin(rotangel);
	data->player.plane_y  = data->player.plane_y * cos(rotangel) + old_plan_x * sin(rotangel);

	raycasting(&data->player, data);
}

void rotate_left(t_cub3d *data)
{
	double rotangel;
	rotangel = -0.20;
	data->player.dir_x  = data->player.dir_x * cos(rotangel) - data->player.dir_y * sin(rotangel);
	data->player.dir_y  = data->player.dir_y * cos(rotangel) + data->player.dir_x * sin(rotangel);
	data->player.plane_x  = data->player.plane_x * cos(rotangel) - data->player.plane_y * sin(rotangel);
	data->player.plane_y  = data->player.plane_y * cos(rotangel) + data->player.plane_x * sin(rotangel);
	raycasting(&data->player, data);
}
