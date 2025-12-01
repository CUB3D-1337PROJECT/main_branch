/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:54:00 by slakhrou          #+#    #+#             */
/*   Updated: 2025/11/30 17:27:33 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	fill_in_map(t_list	*lst, t_cub3d	*data, size_t max_width)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (lst)
	{
		data->map[i] = malloc(max_width + 1);
		if (!data->map[i])
			return (free_allocation(data->map, i),
				putstr_fd("Error\nmalloc failed\n", 2), 1);
		j = 0;
		while (j < max_width)
		{
			if (j < ft_strlen(lst->line))
				data->map[i][j] = lst->line[j];
			else
				data->map[i][j] = ' ';
			j++;
		}
		data->map[i][j] = '\0';
		i++;
		lst = lst->next;
	}
	data->map[i] = NULL;
	return (0);
}

static int	check_closed_map(t_cub3d	*data, int rows, int columns)
{
	int		i;
	char	c;
	int		j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			c = data->map[i][j];
			if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				if (i == 0 || j == 0 || i == rows - 1 || j == columns - 1)
					return (putstr_fd("Error\nMap is not closed\n", 2), 1);
				if (is_space_neighbour(data->map, i, j))
					return (putstr_fd("Error\nMap is not closed\n", 2), 1);
			}
			else if (!is_valid_content(c))
				return (putstr_fd("Error\nInvalid map element\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_store_map(t_list	*lst, t_cub3d	*data, int size)
{
	size_t	max_width;

	max_width = get_max_width(lst);
	if (!lst)
		return (putstr_fd("Error\ninvalid map\n", 2), 1);
	data->map = ft_calloc(size + 1, sizeof(char *));
	if (!data->map)
		return (putstr_fd("Error\ncalloc failed\n", 2), 1);
	if (fill_in_map(lst, data, max_width))
		return (1);
	data->map_length = size;
	data->map_width = max_width;
	if (check_closed_map(data, data->map_length, data->map_width))
		return (1);
	if (validate_map(data, max_width))
		return (1);
	return (0);
}

int	check_empty_line_in_map(int fd, char	*line)
{
	if (line)
	{
		while (line && is_empty(line))
		{
			free(line);
			line = get_next_line(fd, '0');
		}
		if (line && !is_not_map(line) && !is_only_spaces(line))
		{
			putstr_fd("Error\nInvalid map: empty line inside map\n", 2);
			free(line);
			return (1);
		}
		else if (line && is_not_map(line) && !is_only_spaces(line))
		{
			putstr_fd("Error\nwrong content after map\n", 2);
			free(line);
			return (1);
		}
	}
	return (0);
}

int	parse_map(char *line, int fd, t_cub3d *data)
{
	t_list	*lst;
	int		count;

	lst = NULL;
	count = 0;
	while (line)
	{
		if (is_not_map(line) && !is_only_spaces(line))
			break ;
		if (ft_strchr(line, '\t'))
			return (free(line), free_list(&lst),
				putstr_fd("Error\ninvalid map element\n", 2), 1);
		ft_append(&lst, line);
		count++;
		free(line);
		line = get_next_line(fd, '0');
	}
	if (check_empty_line_in_map(fd, line))
		return (free_list(&lst), 1);
	if (ft_store_map(lst, data, count))
	{
		return (free_list(&lst), 1);
	}
	free_list(&lst);
	return (0);
}
