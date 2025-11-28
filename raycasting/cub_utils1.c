/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:57:41 by lhchiban          #+#    #+#             */
/*   Updated: 2025/11/28 14:31:52 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void eventbased(mlx_key_data_t keydata, void *param)
{
	t_cub3d *data = param;
	if (keydata.action == 2 || keydata.action == 1)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		ft_clean(data, 0, 0, 0);
	}
}
static void framebased(void *param)
{
	t_cub3d *data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D ))
    	move_right(data);
    else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
        move_left(data);
    else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
        move_backward(data);
    else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
        move_forward(data);
    if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
        rotate_right(data, data->rotate);
    if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
        rotate_left(data, data->rotate);
    if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
        ft_clean(data, 0, 0, 0);
}
void cub_handel_events(t_cub3d *data)
{

	mlx_key_hook(data->mlx, eventbased, data);
	mlx_loop_hook(data->mlx, framebased, data);
}
