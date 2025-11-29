/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:52:36 by lhchiban          #+#    #+#             */
/*   Updated: 2025/11/29 11:55:51 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	perform_dda(t_cub3d *data, t_rayinfo *ray)
{
	int	hit;

	hit = 0;
	(void)data;
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
		if (ray->map_y < 0 || ray->map_x < 0
			|| ray->map_y >= data->map_length
			|| ray->map_x >= data->map_width)
			break ;
		else if (data->map[(int)ray->map_y][(int)ray->map_x] == '1')
			hit = 1;
	}
}

void	set_dda(t_cub3d *data)
{
	if (data->ray.dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.sidedist_x = (data->ray.raystart_x - data->ray.map_x)
			* data->ray.dest_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.sidedist_x = (data->ray.map_x + 1.0 - data->ray.raystart_x)
			* data->ray.dest_x;
	}
	if (data->ray.dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.sidedist_y = (data->ray.raystart_y - data->ray.map_y)
			* data->ray.dest_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.sidedist_y = (data->ray.map_y + 1.0 - data->ray.raystart_y)
			* data->ray.dest_y;
	}
	perform_dda(data, &data->ray);
}
