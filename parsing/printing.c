/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 17:43:10 by slakhrou          #+#    #+#             */
/*   Updated: 2025/11/28 14:49:21 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	putstr_fd(char	*s, int fd)
{
	int	i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	delete_textures(t_textures	*textures)
{
	if (textures->text_no)
		mlx_delete_texture(textures->text_no);
	if (textures->text_so)
		mlx_delete_texture(textures->text_so);
	if (textures->text_we)
		mlx_delete_texture(textures->text_we);
	if (textures->text_ea)
		mlx_delete_texture(textures->text_ea);
}

int	load_textures(t_cub3d	*data)
{
	data->texts->text_no = mlx_load_png(data->no_tex);
	if (!data->texts->text_no)
	{
		perror("Error\n");
		return (delete_textures(data->texts), 1);
	}
	data->texts->text_so = mlx_load_png(data->so_tex);
	if (!data->texts->text_so)
	{
		perror("Error\n");
		return (delete_textures(data->texts), 1);
	}
	data->texts->text_we = mlx_load_png(data->we_tex);
	if (!data->texts->text_we)
	{
		perror("Error\n");
		return (delete_textures(data->texts), 1);
	}
	data->texts->text_ea = mlx_load_png(data->ea_tex);
	if (!data->texts->text_ea)
	{
		perror("Error\n");
		return (delete_textures(data->texts), 1);
	}
	return (0);
}

int	check_img_extention(char *str, char *exten)
{
	int	len_str;
	int	len_ext;

	len_str = ft_strlen(str);
	len_ext = ft_strlen(exten);
	if (len_str < len_ext)
		return (1);
	if (ft_strcmp(str + len_str - len_ext, exten) != 0)
	{
		return (1);
	}
	return (0);
}
