/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:06:17 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/13 16:10:33 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	validate_map(t_cub3d	*data, int	columns)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (j < columns)
		{
			if (data->map[i][j]== 'N' || data->map[i][j] == 'S'
				|| data->map[i][j]== 'E' || data->map[i][j] == 'W')
			{
				data->counters.nb_players++;
				data->player_view = data->map[i][j];
				data->player_x = j;
				data->player_y = i;
			}
			j++;
		}
		i++;
	}
	if (data->counters.nb_players != 1)
		return (ft_putstr_fd("Error\n player invalid\n", 2), 1);
	return (0);
}

int	is_valid_content(char	c)
{
	return (c == '0' || c == '1' || c == 'N'
			|| c == 'S' || c == 'E' || c == 'W' || c == ' ');
}
int	is_space_neighbour(char	**map, int i, int j)
{
	return (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
		|| map[i][j - 1] == ' ' || map[i][j+ 1] == ' ');
}
void	free_list(t_list	**lst)
{
	t_list	*ptr;
	t_list	*tmp;
	if (!lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr->line);
		free(ptr);
		ptr = tmp;
	}
	*lst = NULL;
}

int	get_max_width(t_list	*lst)
{
	int	max;
	int	len;

	max = 0;
	while (lst)
	{
		len = ft_strlen(lst->line);
		if (len > max)
			max = len;
		lst = lst->next;
	}
	return (max);
}
