/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:34:02 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/06 21:41:48 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// int	ft_isalpha(int c)
// {
// 	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
// 		return (1);
// 	return (0);
// }


int	is_not_map(char	*s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i]  && (s[i] == '\t' || s[i] == ' '))
		i++;
	if (ft_strchr(s, ',') || ft_strchr(s, '/') || ft_strnstr(s, ".xpm", ft_strlen(s)))
		return (1);
	while (s[i])
	{
		if (s[i] && (s[i] == '0' || s[i] == ' ' || s[i] == '1'
			|| s[i] == 'N' || s[i] == 'S' || s[i] == 'W' || s[i] == 'E'))
		{
			if (s[i + 1] && (s[i + 1] == '0' || s[i + 1] == ' ' || s[i + 1] == '1'))
				return (0);
		}
		i++;
	}
	return (1);
}

int	parse_elements_map(int	fd, t_cub3d	*data)
{
	char	*line;
	char	**splits;

	line = get_next_line(fd);
	while (line && is_not_map(line))
	{
		while (!ft_strcmp(line, "\n") || is_empty(line))
		{
			free(line);
			line = get_next_line(fd);
		}
		while (*line == '\t')
			line++;
		splits = ft_split(line, ' ');
		if (!splits)
		{
			free(line);
			ft_putstr_fd("Error\n split failed\n", 2);
			return (1);
		}
		if (fill_texture(line, splits, data))
			return (free(line), free_split( splits), 1);
		free(line);
		free_split(splits);
		line = get_next_line(fd);
	}
	if (check_data_texture(data))
		return (free(line), 1);
	// if (!is_not_map(line))
	// {
	// 	if (parse_map(line, data))
	// 		return (free(line), 1);
	//	free(line);
	// }
	return (0);
}


// int	check_extention(char	*str, char	*exten)
// {
// 	char	*p_point;
// 	//char	*q;

// 	if (!str)
// 		return (1);
// 	p_point = ft_strchr(str, '.');
// 	if (!p_point || ft_strcmp(p_point, exten))
// 	{
// 		ft_putstr_fd("Error\n Invalid map type\n", 2);
// 		return (1);
// 	}
// 	// q = p_point;
// 	// while (q < p_point)
// 	// {
// 	// 	if (*q == '.')
// 	// 	{
// 	// 		if (*(q + 1) != '/')
// 	// 		{
// 	// 			ft_putstr_fd("Error\nInvalid map type\n", 2);
// 	// 			return (1);
// 	// 		}
// 	// 	}
// 	// 	q++;
// 	// }
// 	return (0);
// }

int check_extention(char *str, char *exten)
{
    int len_str = ft_strlen(str);
    int len_ext = ft_strlen(exten);

    if (len_str < len_ext)
        return 1; // too short to be valid

    if (ft_strcmp(str + len_str - len_ext, exten) != 0)
    {
        ft_putstr_fd("Error\nInvalid map type\n", 2);
        return 1;
    }
    return 0;
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
