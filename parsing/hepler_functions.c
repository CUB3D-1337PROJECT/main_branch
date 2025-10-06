/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hepler_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:42:09 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/06 20:57:26 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_cub3d(t_cub3d	*data)
{
	if (data->no_tex)
		free(data->no_tex);
	if (data->no_tex)
		free(data->so_tex);
	if (data->so_tex)
		free(data->we_tex);
	if (data->no_tex)
		free(data->ea_tex);
	if (data->map)
		free_split(data->map);
}




int	check_data_texture(t_cub3d	*data)
{
	if (data->counters.nb_ceiling != 1 || data->counters.nb_no_tex != 1
	|| data->counters.nb_so_tex != 1 || data->counters.nb_we_tex != 1
	|| data->counters.nb_ea_tex!= 1 || data->counters.nb_flour != 1)
		return (ft_putstr_fd("Error\n invalid textures\n", 2), 1);
	return (0);
}

int	count_elment(char	**str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		count++;
		i++;
	}
	return (count);
}
