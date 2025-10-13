/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:54:00 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/13 18:05:23 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_append(t_list	**lst, char	*line)
{
	t_list	*ptr;
	t_list	*node;

	if (!lst)
		return ;
	node = ft_calloc(1, sizeof(t_list));
	if (!node)
	{
		free_list(lst);
		return ;
	}
	node->line = ft_copy(line);
	node->next = NULL;
	ptr = *lst;
	if (!*lst)
	{
		*lst = node;
		node -> next = NULL;
		return ;
	}
	while (ptr -> next)
		ptr = ptr-> next;
	ptr -> next = node;
	node -> next = NULL;
}

static int	fill_in_map(t_list	*lst, t_cub3d	*data, int	max_width)
{
	int		i;
	int		j;

	i = 0;
	while (lst)
	{
		data->map[i] = malloc(max_width + 1);
		if (!data->map[i])
			return (free_allocation(data->map, i),
				ft_putstr_fd("Error\n malloc failed\n", 2), 1);
		j = 0;
		while (j < max_width)
		{
			if (j < (int) ft_strlen(lst->line))
				data->map[i][j] = lst->line[j];
			else
				data->map[i][j] = '1';
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
			if (c == '0' || c == 'N' || c == 'S' ||c == 'E' || c == 'W')
			{
				if (i == 0 || j == 0 || i == rows - 1 || j == columns - 1)
					return (ft_putstr_fd("Error\n Map is not closed\n", 2), 1);
				if (is_space_neighbour(data->map, i, j))
					return (ft_putstr_fd("Error\n Map is not closed\n", 2), 1);
			}
			else if (!is_valid_content(c))
				return (ft_putstr_fd("Error\n Invalid map elemnt\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_store_map(t_list	*lst, t_cub3d	*data, int	size)
{
	int		max_width;

	max_width = get_max_width(lst);
	if (!lst)
		return (ft_putstr_fd("Error\n invalid map\n", 2), 1);
	data->map = ft_calloc(size + 1, sizeof(char*));
	if (!data->map)
		return (ft_putstr_fd("Error\n calloc failed\n", 2), 1);
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

// int	parse_map(char	*line, int fd, t_cub3d	*data)
// {
// 	t_list	*lst;
// 	int		count;
// 	//int		started_map;

// 	//started_map = 0;
// 	count = 0;
// 	lst = NULL;
// 	while (line && !is_not_map(line))
// 	{
// 		printf("\n this is the  get-line[%s]", line);
// 		// if (line && is_empty(line)) //!line || !ft_strcmp(line, "\n"))//
// 		// {
// 		// 	ft_putstr_fd("Error\n Invalid map: spces between lines\n", 2);
// 		// 	free_list(&lst);
// 		// 	free(line);
// 		// 	return (1);
// 		// // }
// 		// if (!is_not_map(line))
// 		// {
// 			ft_append(&lst, line);
// 			count++;
// 			free(line);
// 			line = get_next_line(fd);
// 		// }
// 		// else
// 		// 	break;
// 	}
// 	//if (is_empty(line))
// 	if (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		if (!is_not_map(line))
// 		{
// 			ft_putstr_fd("Error\n Invalid map: spces between lines\n", 2);
// 			free_list(&lst);
// 			free(line);
// 			return (1);
// 		}
// 	}
// 	// if (line)
// 	// {

// 	// }
// 	// while (is_empty(line))
// 	// 	{
// 	// 		free(line);
// 	// 		line = get_next_line(fd);
// 	// 	}
// 	if (ft_store_map(lst, data, count))
// 		return (free_list(&lst), 1);
// 	free_list(&lst);
// 	return (0);
// }



// int	parse_map(char	*line, int fd, t_cub3d	*data)
// {
// 	t_list	*lst;
// 	int		count;
// 	//int		started_map;

// 	//started_map = 0;
// 	count = 0;
// 	lst = NULL;
// 	while (line)
// 	{
// 		printf("\n this is the  get-line[%s]", line);
// 		// if (line && is_empty(line)) //!line || !ft_strcmp(line, "\n"))//
// 		// {
// 		// 	ft_putstr_fd("Error\n Invalid map: spces between lines\n", 2);
// 		// 	free_list(&lst);
// 		// 	free(line);
// 		// 	return (1);
// 		// // }
// 		if (!is_not_map(line))
// 		{
// 			ft_append(&lst, line);
// 			count++;
// 			free(line);
// 			line = get_next_line(fd);
// 		}
// 		else
// 		{
// 			while (line)
// 			{
// 				/* code */
// 			}


// 		}
// 	}
// 	//if (is_empty(line))
// 	if (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		if (!is_not_map(line))
// 		{
// 			ft_putstr_fd("Error\n Invalid map: spces between lines\n", 2);
// 			free_list(&lst);
// 			free(line);
// 			return (1);
// 		}
// 	}
// 	// if (line)
// 	// {

// 	// }
// 	// while (is_empty(line))
// 	// 	{
// 	// 		free(line);
// 	// 		line = get_next_line(fd);
// 	// 	}
// 	if (ft_store_map(lst, data, count))
// 		return (free_list(&lst), 1);
// 	free_list(&lst);
// 	return (0);
// }


int	parse_map(char *line, int fd, t_cub3d *data)
{
	t_list	*lst;
	int		count;

	lst = NULL;
	count = 0;

	while (line)
	{
		printf("\n this is the  get-line[%s]", line);
		if (is_not_map(line)) // reached line after map (textures, etc.)
			break;
		ft_append(&lst, line);
		count++;
		free(line);
		line = get_next_line(fd);
	}
	if (is_empty(line))
	{
			while (line && is_empty(line))
			{
				free(line);
				line = get_next_line(fd);
			}
			if (line && !is_not_map(line))
			{
				ft_putstr_fd("Error\nInvalid map: empty line inside map\n", 2);
				free(line);
				free_list(&lst);
				return (1);
			}
			else if (line && is_not_map(line))
			{
				ft_putstr_fd("Error\n wrong content after map\n", 2);
				free(line);
				free_list(&lst);
				return (1);
			}
		}
	// Build final normalized map
	if (ft_store_map(lst, data, count))
	{
		free_list(&lst);
		return (1);
	}

	free_list(&lst);
	if (line)
		free(line);
	return (0);
}
