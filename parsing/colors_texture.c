/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:10:24 by slakhrou          #+#    #+#             */
/*   Updated: 2025/11/11 16:05:37 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

uint32_t	create_trgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
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
