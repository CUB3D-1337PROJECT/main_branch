/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:34:02 by slakhrou          #+#    #+#             */
/*   Updated: 2025/10/30 21:42:21 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_not_map(char *s)
{
	int	i;
	int	has_valid_char;

	if (!s)
		return (1);
	i = 0;
	has_valid_char = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (ft_strchr(s, ',') || ft_strchr(s, '/')
		|| ft_strnstr(s, ".png", ft_strlen(s)))
		return (1);
	if (s[i] && !ft_strchr("01NSEW", s[i]))
		return (1);
	while (s[i] && s[i] != '\n')
	{
		if (!ft_strchr(" 01NSEW\t", s[i]))
			return (1);
		if (ft_strchr(" 01NSEW", s[i]))
			has_valid_char = 1;
		i++;
	}
	if (!has_valid_char)
		return (1);
	return (0);
}

int	parse_textures(char	**line, int fd, t_cub3d	*data)
{
	char	**splits;

	while (*line && is_not_map(*line))
	{
		while (*line && is_empty(*line))
		{
			free(*line);
			*line = get_next_line(fd);
		}
		if (!*line)
			return (putstr_fd("Error\n no map found \n", 2), 1);
		if (!is_not_map(*line))
			break ;
		splits = ft_split(*line, " \n\t");
		if (!splits)
			return (putstr_fd("Error\n split failed\n", 2), free(*line), 1);
		if (fill_texture(*line, splits, data))
			return (free(*line), free_split(splits), 1);
		free_split(splits);
		free(*line);
		*line = get_next_line(fd);
	}
	return (0);
}

int	parse_elements_map(int fd, t_cub3d	*data)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		putstr_fd("Error\n invalid map file contents (empty) \n", 2);
		return (1);
	}
	if (!is_not_map(line))
	{
		free(line);
		putstr_fd("Error\n invalid map file (wrong order)\n", 2);
		return (1);
	}
	if (parse_textures(&line, fd, data))
		return (1);
	if (check_data_texture(data, line))
		return (free(line), 1);
	if (!is_not_map(line))
	{
		if (parse_map(line, fd, data))
			return (1);
	}
	return (0);
}

int	check_extention(char *str, char *exten)
{
	int	len_str;
	int	len_ext;

	len_str = ft_strlen(str);
	len_ext = ft_strlen(exten);
	if (len_str < len_ext)
		return (1);
	if (ft_strcmp(str + len_str - len_ext, exten) != 0)
	{
		putstr_fd("Error\nInvalid map file type\n", 2);
		return (1);
	}
	return (0);
}

int	parsing(int argc, char	**argv, t_cub3d	*data)
{
	int	fd;

	if (argc != 2)
	{
		putstr_fd("Error\nWrong number of arguments\n", 2);
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
	data->texts = ft_calloc(1, sizeof(t_textures));
	if (!data->texts)
		return (putstr_fd("Error\n calloc failed\n", 2), 1);
	return (0);
}
