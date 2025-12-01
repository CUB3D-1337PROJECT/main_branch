/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:21:49 by lhchiban          #+#    #+#             */
/*   Updated: 2025/12/01 16:50:29 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_clean(t_cub3d *data, char *err_type,
		char *err_msg, int err_exit)
{
	if (err_type)
	{
		printf("err\n");
		putstr_fd("cub : error: ", 2);
		putstr_fd(err_type, 2);
	}
	if (err_msg)
	{
		printf("err\n");
		putstr_fd("cub : error: ", 2);
		putstr_fd(err_msg, 2);
	}
	if (!data)
		exit(err_exit);
	if (data->img && data->mlx)
		mlx_delete_image(data->mlx, data->img);
	if (data->mlx)
		mlx_terminate(data->mlx);
	free_cub3d(data, 'e');
	exit(err_exit);
}
