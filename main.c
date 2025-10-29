/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spi <spi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:38:45 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/25 22:09:21 by spi              ###   ########.fr       */
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

    // Attach the image to the window once
    if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
        ft_clean(data, "MLX42", "Failed to attach image", 1);
}


// int	main(int argc, char	**argv)
// {
// 	t_cub3d	*data;
	
// 	data = ft_calloc(1, sizeof(t_cub3d));
// 	if (!data)
// 	{
// 		putstr_fd("Error\n calloc failed\n", 2);
// 		return (1);
// 	}
// 	if (parsing(argc, argv, data))
// 	    return (free_cub3d(data), 1);
    
//     cub_connection(data);
// 	int i, j;
// 	i = 0;
// 	while (data->map[i])
// 	{
    // 		j = 0;
    // 		while (data->map[i][j])
    // 		{
        // 			printf("%i\n", j);
        // 			/* code */
        // 			printf("%i\n", i);
        // 			j++;
        // 		}
        // 		i++;
		
        // 	}
        // 	for (int y = 0; y < HEIGHT; y++)
        // 		for (int x = 0; x < WIDTH; x++)
// 			mlx_put_pixel(data->img, x, y, 0x202040FF);  // dark blue

// 		// for this function you gotta use it right after int_mlx !!!
// 	raycasting(&data->player, data);
// 	mlx_loop(data->mlx);
// 	free_cub3d(data);
// 	return (0);
// }
static void init_player_info(t_cub3d *data)
{
    data->player.pos_x = 3.5;
    data->player.pos_y = 3.5;
    data->player.dir_x = -1;
    data->player.dir_y = 0;
    data->player.plane_x = 0;
    data->player.plane_y = 0.66;
}

int main(int argc, char **argv)
{
    t_cub3d *data = ft_calloc(1, sizeof(t_cub3d));
    if (!data)
    return (putstr_fd("Error\ncalloc failed\n", 2), 1);
    
    if (parsing(argc, argv, data))
    return (free_cub3d(data), 1);
    
    cub_connection(data);
    init_player_info(data);
    raycasting(&data->player, data);
    if (load_textures(data))
        return (free_cub3d(data), 1);
    cub_handel_events(data);
    mlx_loop(data->mlx);
    free_cub3d(data);
    return (0);
}
