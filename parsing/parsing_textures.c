/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:54:14 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/06 21:40:10 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*find_identifier(char	*first_split)
{
	int		j;
	char	*identifier;
	char *ident[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};

	j = 0;
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

static int	fill_data_texture(char	*ident,char	*path_texture,t_cub3d *data, int fd)
{
	fd = open(path_texture, O_RDONLY);
	printf("\n FD: %d PATH:%s\n", fd, path_texture);
	if (fd < 0)
		return (perror("Error\n can't open texture\n"), 1);
	close(fd);
	if (!ft_strcmp(ident, "NO"))
	{
		data->no_tex = ft_strdup(path_texture);
		data->counters.nb_no_tex++;
	}
	else if (!ft_strcmp(ident, "SO"))
	{
		data->so_tex = ft_strdup(path_texture);
		data->counters.nb_so_tex++;
	}
	else if (!ft_strcmp(ident, "WE"))
	{
		data->we_tex = ft_strdup(path_texture);
		data->counters.nb_we_tex++;
	}
	else if (!ft_strcmp(ident, "EA"))
	{
		data->ea_tex = ft_strdup(path_texture);
		data->counters.nb_ea_tex++;
	}
	return (0);
}


static int	check_rgb(char	**split_colors, int	rgb[3])
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

static int	fill_data_colors(char	*ident, char	*color, t_cub3d	*data)
{
	char	**split_colors;
	int		rgb[3];

	split_colors = ft_split(color, ',');
	if (!split_colors)
		return (1);
	if (count_elment(split_colors) != 3 || check_rgb(split_colors, rgb))
		return (free_split(split_colors), ft_putstr_fd("Error\n wrong in rgb colors\n", 2), 1);
	if (!ft_strcmp(ident, "F"))
	{
		data->flour = rgb;
		data->counters.nb_flour++;
	}
	else if (!ft_strcmp(ident, "C"))
	{
		data->ceiling = rgb;
		data->counters.nb_ceiling++;
	}
	return (0);
}

int	fill_texture(char	*line, char	**splits, t_cub3d	*data)
{
	int		count;
	char	*ident;
	int		fd;

	fd = -1;
	count = count_elment(splits);
	printf("\n count splited %d\n", count);
	if (count != 2)
		return (ft_putstr_fd("Error\n wrong texture\n", 2), 1);
	ident = find_identifier(splits[0]);
	if (!ident)
		return (ft_putstr_fd("Error\n wrong texture identifier\n", 2), 1);
	if (*(ft_strnstr(line, ident, ft_strlen(line)) + ft_strlen(ident)) != ' ')
		return (free(ident), ft_putstr_fd("Error\n there is no space after identifier\n", 2), 1);
	if (ft_strcmp(ident, "F") && ft_strcmp(ident, "C"))
	{
		if (fill_data_texture(ident,splits[1], data, fd))
			return (free(ident), 1);
	}
	else if (ft_strcmp(ident, "F") == 0 || !ft_strcmp(ident, "C"))
	{
		if (fill_data_colors(ident, splits[1], data))
			return (free(ident), 1);
	}
	return (free(ident), 0);
}
