/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:57:47 by lhchiban          #+#    #+#             */
/*   Updated: 2025/10/08 02:36:51 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

static void cub_connection(cub_data_t *data)
{
    data->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
    if (data->mlx == NULL)
        exit(1);
	data->map = cub_set_map();
	cub_draw_map(data);
	cub_handel_events(&data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}

int main(int ac, char **av)
{
    cub_data_t data;
	// data = NULL;
	(void)av;
	(void)ac;
    // if (ac != 2)
    // 	return (1);
    cub_connection(&data);
    return 0;
}

