/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:38:45 by slakhrou          #+#    #+#             */
/*   Updated: 2025/12/01 16:50:39 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cub_connection(t_cub3d *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!data->mlx)
		ft_clean(data, "MLX42 Instance", "Failed to init MLX", 1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		ft_clean(data, "MLX42 img", "Failed to create image", 1);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		ft_clean(data, "MLX42", "Failed to attach image", 1);
	return ;
}

static void	init_player_info(t_cub3d *data)
{
	data->player.pos_x = data->player_x + 0.5;
	data->player.pos_y = data->player_y + 0.5;
	if (data->player_view == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
	}
	else if (data->player_view == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
	}
	else if (data->player_view == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = -0.66;
	}
	else if (data->player_view == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
	}
	else
		return ;
}

// void f()
// {
// 	system("leaks cub3D");
// }
int	main(int argc, char **argv)
{
	t_cub3d	*data;

	// atexit(f);
	data = ft_calloc(1, sizeof(t_cub3d));
	if (!data)
		return (free(data), putstr_fd("Error\ncalloc failed\n", 2), 1);
	if (parsing(argc, argv, data))
		return (free_cub3d(data, 'l'), 1);
	if (load_textures(data))
		return (free_cub3d(data, 'l'), 1);
	cub_connection(data);
	init_player_info(data);
	raycasting(&data->player, data);
	cub_handel_events(data);
	mlx_loop(data->mlx);
	return (0);
}
