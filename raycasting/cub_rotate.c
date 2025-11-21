/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:49:27 by lhchiban          #+#    #+#             */
/*   Updated: 2025/11/13 16:54:06 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void rotate_right(t_cub3d *data)
{
	double rotangeR;
	rotangeR = 0.10;
	double old_plan_x;
	double old_dir_x;
	old_plan_x = data->player.plane_x;
	old_dir_x = data->player.dir_x;
	data->player.dir_x  = old_dir_x * cos(rotangeR) - data->player.dir_y * sin(rotangeR);
	data->player.dir_y  = data->player.dir_y * cos(rotangeR) + old_dir_x * sin(rotangeR);
	data->player.plane_x  = old_plan_x * cos(rotangeR) - data->player.plane_y * sin(rotangeR);
	data->player.plane_y  = data->player.plane_y * cos(rotangeR) + old_plan_x * sin(rotangeR);
	raycasting(&data->player, data);
}

void rotate_left(t_cub3d *data)
{
	double rotangeL;
	rotangeL = -0.10;
	double old_plan_x;
	double old_dir_x;
	old_plan_x = data->player.plane_x;
	old_dir_x = data->player.dir_x;
	data->player.dir_x  = old_dir_x * cos(rotangeL) - data->player.dir_y * sin(rotangeL);
	data->player.dir_y  = data->player.dir_y * cos(rotangeL) + old_dir_x * sin(rotangeL);
	data->player.plane_x  = old_plan_x * cos(rotangeL) - data->player.plane_y * sin(rotangeL);
	data->player.plane_y  = data->player.plane_y * cos(rotangeL) + old_plan_x * sin(rotangeL);
	raycasting(&data->player, data);
}
