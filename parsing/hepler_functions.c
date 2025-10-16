/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hepler_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:42:09 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/16 14:53:31 by slakhrou         ###   ########.fr       */
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
	if (data->texts)
	{
		delete_textures(data->texts);
		free(data->texts);
	}
	free(data);
}

int	check_data_texture(t_cub3d	*data)
{
	if (data->counters.nb_ceiling != 1 || data->counters.nb_no_tex != 1
		|| data->counters.nb_so_tex != 1 || data->counters.nb_we_tex != 1
		|| data->counters.nb_ea_tex != 1 || data->counters.nb_flour != 1)
	{
		putstr_fd("Error\n invalid map file contents (textures)\n", 2);
		return (1);
	}
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

char	*find_identifier(char	*first_split)
{
	int		j;
	char	*identifier;
	char	*ident[7];

	j = 0;
	ident[0] = "NO";
	ident[1] = "SO";
	ident[2] = "WE";
	ident[3] = "EA";
	ident[4] = "F";
	ident[5] = "C";
	ident[6] = NULL;
	if (!first_split)
		return (NULL);
	while (ident[j])
	{
		if (ft_strcmp(first_split, ident[j]) == 0)
		{
			identifier = ft_strdup(ident[j]);
			return (identifier);
		}
		j++;
	}
	return (NULL);
}

int	check_rgb(char	**split_colors, int rgb[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (parse_int(split_colors[i]))
			return (1);
		rgb[i] = ft_atoi(split_colors[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (1);
		i++;
	}
	return (0);
}
