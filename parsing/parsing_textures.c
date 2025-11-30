/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:54:14 by slakhrou          #+#    #+#             */
/*   Updated: 2025/11/30 17:02:38 by slakhrou         ###   ########.fr       */
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

static int	fill_data_texture(char	*line, char	*ident, t_cub3d *data)
{
	int		fd;
	char	*path;

	path = get_path(line, ident);
	if (!path)
		return (1);
	if (check_double_slash(path))
		return (free(path), putstr_fd("Error\n invalid path texture\n", 2), 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (free(path), perror("Error\n can't open texture"), 1);
	else if (check_img_extention(path, ".png"))
	{
		putstr_fd("Error\n can't open texture (invalid picture)\n", 2);
		close(fd);
		free(path);
		return (1);
	}
	close(fd);
	if (assign_texture(ident, path, data))
		return (free(path), 1);
	free(path);
	return (0);
}

static int	fill_data_colors(char *ident, char *color, t_cub3d *data)
{
	int	*rgb;

	if (parse_rgb_values(color, &rgb))
		return (1);
	if (!ft_strcmp(ident, "F"))
		assign_floor_color(rgb, data);
	else if (!ft_strcmp(ident, "C"))
		assign_ceiling_color(rgb, data);
	return (0);
}

int	fill_texture(char	*line, char	**splits, t_cub3d	*data)
{
	int		count;
	char	*ident;

	count = count_elment(splits);
	if (count != 2 && splits[0]
		&& (splits[0][0] == 'F' || splits[0][0] == 'C'))
		return (putstr_fd("Error\n Invalid line  Wrong element in file\n"
				, 2), 1);
	ident = find_identifier(splits[0]);
	if (!ident)
		return (putstr_fd("Error\n wrong elemnts in file\n", 2), 1);
	if (ft_strcmp(ident, "F") && ft_strcmp(ident, "C"))
	{
		if (fill_data_texture(line, ident, data))
			return (free(ident), 1);
	}
	else if (ft_strcmp(ident, "F") == 0 || !ft_strcmp(ident, "C"))
	{
		if (fill_data_colors(ident, splits[1], data))
			return (free(ident), 1);
	}
	return (free(ident), 0);
}
