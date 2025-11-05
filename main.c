/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:38:45 by slakhrou          #+#    #+#             */
/*   Updated: 2025/11/05 15:43:30 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char	**argv)
{
	t_cub3d	*data;

	data = ft_calloc(1, sizeof(t_cub3d));
	if (!data)
	{
		putstr_fd("Error\n calloc failed\n", 2);
		return (1);
	}
	if (parsing(argc, argv, data))
		return (free_cub3d(data), 1);
	// for this function you gotta use it right after int_mlx !!!
	if (load_textures(data))
		return (free_cub3d(data), 1);
	free_cub3d(data);
	return (0);
}
