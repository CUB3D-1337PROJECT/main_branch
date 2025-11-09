/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spi <spi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:57:41 by lhchiban          #+#    #+#             */
/*   Updated: 2025/11/07 13:28:13 by spi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void callback(mlx_key_data_t keydata, void *param)
{
	t_cub3d *data = param;
	if (keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_D)
			move_right(data);
		else if (keydata.key == MLX_KEY_A)
			move_left(data);
		else if (keydata.key == MLX_KEY_S)
			move_backward(data);
		else if (keydata.key == MLX_KEY_W)
			move_forward(data);
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == 2)
		rotate_right(data);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == 2)
		rotate_left(data);
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_clean(data, 0, 0, 0);
}

void cub_handel_events(t_cub3d *data)
{
	mlx_key_hook(data->mlx, callback, data);
}
