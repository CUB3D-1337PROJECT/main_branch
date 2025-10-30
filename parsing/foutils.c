/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:38:36 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/29 16:46:21 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_allocation(char **arr, int j)
{
	while (j-- > 0)
		free(arr[j]);
	free(arr);
}

void	ft_append(t_list	**lst, char	*line)
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

int	is_empty(char	*line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_two_commas(char	*color)
{
	int	i;
	int	commas;

	i = 0;
	commas = 0;
	while (color[i])
	{
		if (color[i] == ',')
			commas++;
		i++;
	}
	if (commas != 2)
		return (1);
	return (0);
}
