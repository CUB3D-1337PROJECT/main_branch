/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:06:06 by lhchiban          #+#    #+#             */
/*   Updated: 2025/11/30 16:53:03 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static uint32_t	create_trgb(int r, int g, int b)
{
	return (255 << 24 | b << 16 | g << 8 | r);
}

int	parse_rgb_values(char *color, int	**rgb)
{
	char	**split_colors;

	split_colors = ft_split(color, ",");
	if (!split_colors)
		return (1);
	*rgb = malloc(sizeof(int) * 3);
	if (!*rgb)
	{
		free_split(split_colors);
		return (1);
	}
	if (count_elment(split_colors) != 3 || check_rgb(split_colors, *rgb, color))
	{
		free_split(split_colors);
		putstr_fd("Error\nwrong in rgb colors\n", 2);
		free(*rgb);
		*rgb = NULL;
		return (1);
	}
	free_split(split_colors);
	return (0);
}

void	assign_floor_color(int *rgb, t_cub3d *data)
{
	if (!data->flour)
	{
		data->flour = rgb;
		data->rgb_color_flour = create_trgb(rgb[0], rgb[1], rgb[2]);
	}
	else
		free(rgb);
	data->counters.nb_flour++;
}

void	assign_ceiling_color(int *rgb, t_cub3d *data)
{
	if (!data->ceiling)
	{
		data->ceiling = rgb;
		data->rgb_color_ceiling = create_trgb(rgb[0], rgb[1], rgb[2]);
	}
	else
		free(rgb);
	data->counters.nb_ceiling++;
}

int	check_double_slash(char *path_texture)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(path_texture);
	if (path_texture[len - 1] == '/')
		return (1);
	while (path_texture[i])
	{
		if (path_texture[i] == '/')
		{
			if (path_texture[i + 1] && path_texture[i + 1] == '/')
				return (1);
		}
		i++;
	}
	return (0);
}
