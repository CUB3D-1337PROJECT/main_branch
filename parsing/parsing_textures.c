/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:54:14 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/04 21:30:17 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


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
int	fill_texture(char	*line, char	**splits, t_cub3d	*data)
{
	int		i;
	int		count;
	char	*ident;


	i = 0;
	count = count_elment(splits);
	if (count <= 1)
		return (free_cub3(*data), 1);
	ident = find_identifier(splits[0]);
	if (ident)
	{
		if (ft_(line, i))
	}







}
