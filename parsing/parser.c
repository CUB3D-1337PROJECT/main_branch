/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:34:02 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/04 19:19:12 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"




int	parse_elements_map(int	fd, t_cub3d	data)
{
	char	*line;

}


int	check_extention(char	*str, char	*exten)
{
	char	*p_point;
	char	*q;

	if (!str)
		return (1);
	p_point = ft_strchr(str, '.');
	if (!p_point || ft_strcmp(p_point, exten))
	{
		ft_putstr_fd("Error\n Invalid map type\n", 2);
		return (1);
	}
	q = p_point;
	while (q < p_point)
	{
		if (*q == '.')
		{
			if (*(q + 1) != '/')
			{
				ft_putstr_fd("Error\nInvalid map type\n", 2);
				return (1);
			}
		}
		q++;
	}
	return (0);
}

int	parsing(int	argc, char	**argv, t_cub3d	*data)
{
	int	fd;

	if (argc > 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		return (1);
	}
	if (check_extention(argv[1], ".cub"))
		return (1);
	fd = open(argv[1], O_RDONLY, 0666);
	if (fd < 0)
	{
		perror("Error\n");
		return (1);
	}
	if (parse_elements_map(fd, data))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
