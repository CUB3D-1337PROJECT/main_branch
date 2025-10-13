/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:54:14 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/13 18:42:44 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	assign_tex_field(char **tex_field, char *path_texture)
{
	char	*dup;

	if (!*tex_field)
	{
		dup = ft_strdup(path_texture);
		if (!dup)
			return (1);
		*tex_field = dup;
	}
	return (0);
}

static int	assign_texture(char *ident, char *path_texture, t_cub3d *data)
{
	if (!ft_strcmp(ident, "NO"))
	{
		if (assign_tex_field(&data->no_tex, path_texture) != 0)
			return (1);
		data->counters.nb_no_tex++;
	}
	else if (!ft_strcmp(ident, "SO"))
	{
		if (assign_tex_field(&data->so_tex, path_texture) != 0)
			return (1);
		data->counters.nb_so_tex++;
	}
	else if (!ft_strcmp(ident, "WE"))
	{
		if (assign_tex_field(&data->we_tex, path_texture) != 0)
			return (1);
		data->counters.nb_we_tex++;
	}
	else if (!ft_strcmp(ident, "EA"))
	{
		if (assign_tex_field(&data->ea_tex, path_texture) != 0)
			return (1);
		data->counters.nb_ea_tex++;
	}
	return (0);
}

static int	fill_data_texture(char	*ident,char	*path_texture,t_cub3d *data)
{
	int	fd;

	fd = open(path_texture, O_RDONLY);
	printf("\n FD: %d PATH[%s]\n", fd, path_texture);
	if (fd < 0)
		return (perror("Error\n can't open texture\n"), 1);
	close(fd);
	if (assign_texture(ident, path_texture, data))
		return (1);
	return (0);
}

static int	fill_data_colors(char	*ident, char	*color, t_cub3d	*data)
{
	char	**split_colors;
	int		rgb[3];

	split_colors = ft_split(color, ",");
	if (!split_colors)
		return (1);
	if (count_elment(split_colors) != 3 || check_rgb(split_colors, rgb))
		return (free_split(split_colors), ft_putstr_fd("Error\n wrong in rgb colors\n", 2), 1);
	if (!ft_strcmp(ident, "F"))
	{
		if (!data->flour)
			data->flour = rgb;
		data->counters.nb_flour++;
	}
	else if (!ft_strcmp(ident, "C"))
	{
		if (!data->ceiling)
			data->ceiling = rgb;
		data->counters.nb_ceiling++;
	}
	free_split(split_colors);
	return (0);
}

int	fill_texture(char	*line, char	**splits, t_cub3d	*data)
{
	int		count;
	char	*ident;

	count = count_elment(splits);
	printf("\n count splited %d  splited[%s]\n", count, splits[0]);
	if (count != 2  && splits[0])//|| *splits == NULL)
			return (ft_putstr_fd("Error\n wrong texture\n", 2), 1);
	ident = find_identifier(splits[0]);
	if (!ident)
		return (ft_putstr_fd("Error\n wrong texture identifier\n", 2), 1);
	if (*(ft_strnstr(line, ident, ft_strlen(line)) + ft_strlen(ident)) != ' '
	&& *(ft_strnstr(line, ident, ft_strlen(line)) + ft_strlen(ident)) != '\t')
		return (free(ident), ft_putstr_fd("Error\n there is no space after identifier\n", 2), 1);
	if (ft_strcmp(ident, "F") && ft_strcmp(ident, "C"))
	{
		if (fill_data_texture(ident,splits[1], data))
			return (free(ident), 1);
	}
	else if (ft_strcmp(ident, "F") == 0 || !ft_strcmp(ident, "C"))
	{
		if (fill_data_colors(ident, splits[1], data))
			return (free(ident), 1);
	}
	return (free(ident), 0);
}
