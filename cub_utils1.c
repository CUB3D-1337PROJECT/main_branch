/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:57:41 by lhchiban          #+#    #+#             */
/*   Updated: 2025/10/08 05:29:43 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void callback(mlx_key_data_t keydata, void *param)
{
	cub_data_t *data = param;
	if (keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_D && data->player_x < WIDTH)
			move_right(data);
		else if (keydata.key == MLX_KEY_A && data->player_x > 0)
			move_left(data);
		else if (keydata.key == MLX_KEY_S && data->player_y < HEIGHT)
			move_backward(data);
		else if (keydata.key == MLX_KEY_W && data->player_y > 8)
			move_forward(data);
	}
	if (keydata.key == MLX_KEY_RIGHT)
		rotate_right(data); // rotate right
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
		rotate_left(data); // rotate left
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		free(data->map);
		mlx_close_window(data->mlx);
		exit(0);
	}
}

void cub_handel_events(cub_data_t **data)
{
	mlx_key_hook((*data)->mlx, callback, *data);
}
char **cub_set_map(void)
{
	char **map;

	map = malloc(sizeof(char *) * 15);
	map[0] = "        1111111111111111111111111";
	map[1] = "        1000000000110000000000001";
	map[2] = "        1011000001110000000000001";
	map[3] = "        1001000000000000000000001";
	map[4] = "111111111011000001110000000000001";
	map[5] = "100000000011000001110111111111111";
	map[6] = "11110111111111011100000010001";
	map[7] = "11110111111111011101010010001";
	map[8] = "11000000110101011100000010001";
	map[9] = "10000000000000001100000010001";
	map[10] = "10000000000000001101010010001";
	map[11] = "1100000111010101111101111W00111";
	map[12] = "11110111 1110101 101111010001";
	map[13] = "11111111 1111111 111111111111";
	map[14] = NULL;
	return (map);
}
