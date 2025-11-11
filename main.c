/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spi <spi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:38:45 by slakhrou          #+#    #+#             */
/*   Updated: 2025/11/07 14:04:11 by spi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void cub_connection(t_cub3d *data)
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

static void init_player_info(t_cub3d *data)
{
    data->player.pos_x = data->player_x ;
    data->player.pos_y = data->player_y ;
	if (data->player_view == 'S')
	{
		data->player.pos_x = data->player_x + 0.5;
    	data->player.pos_y = data->player_y ;
		data->player.dir_x = 0;
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
	}
	else if (data->player_view == 'N')
	{
		data->player.pos_x = data->player_x + 0.5;
    	data->player.pos_y = data->player_y ;
		data->player.dir_x = 0;
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
	}
    else 	if (data->player_view == 'W')
	{
		data->player.pos_x = data->player_x ;
    	data->player.pos_y = data->player_y + 0.5;
		data->player.dir_x = -1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = -0.66;
	}
	else if (data->player_view == 'E')
	{
		data->player.pos_x = data->player_x ;
    	data->player.pos_y = data->player_y + 0.5;
		data->player.dir_x = 1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
	}
	else
		return ;
}

int main(int argc, char **argv)
{
    t_cub3d *data = ft_calloc(1, sizeof(t_cub3d));
    if (!data)
        return (putstr_fd("Error\ncalloc failed\n", 2), 1); 
    if (parsing(argc, argv, data))
        return (free_cub3d(data), 1);
    cub_connection(data);
    if (load_textures(data))
        return (free_cub3d(data), 1);
    init_player_info(data);
    raycasting(&data->player, data);
    cub_handel_events(data);
    mlx_loop(data->mlx);
    free_cub3d(data);
    return (0);
}
