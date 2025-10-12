/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:59:00 by lhchiban          #+#    #+#             */
/*   Updated: 2025/10/08 01:56:48 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void move_right(cub_data_t *data)
{
	data->player_x += 16;
	mlx_delete_image(data->mlx,  data->playerv_img);
	cub_create_pimg(data);
	cub_creat_pvimg(data);
}

void move_left(cub_data_t *data)
{
	data->player_x -= 16;
	mlx_delete_image(data->mlx,  data->playerv_img);
	cub_create_pimg(data);
	cub_creat_pvimg(data);
}
void move_forward(cub_data_t *data)
{
	data->player_y -= 16;
	mlx_delete_image(data->mlx,  data->playerv_img);
	cub_create_pimg(data);
	cub_creat_pvimg(data);
}

void move_backward(cub_data_t *data)
{
	data->player_y += 16;
	mlx_delete_image(data->mlx,  data->playerv_img);
	cub_create_pimg(data);
	cub_creat_pvimg(data);
}
