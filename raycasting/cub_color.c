/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhchiban <lhchiban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:28:51 by lhchiban          #+#    #+#             */
/*   Updated: 2025/11/30 15:26:25 by lhchiban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	sample_texture(t_texture_colors *tc, t_cub3d *data)
{
	tc->tex_y = (int)(data->ray.tex_pos);
	if (tc->tex_y < 0)
		tc->tex_y = 0;
	if (tc->tex_y >= (int)data->curr_texture->height)
		tc->tex_y = (int)data->curr_texture->height - 1;
	tc->tex_x = data->ray.tex_x;
	if (tc->tex_x < 0)
		tc->tex_x = 0;
	if (tc->tex_x >= (int)data->curr_texture->width)
		tc->tex_x = (int)data->curr_texture->width - 1;
	tc->color = ((uint32_t *)data->curr_texture->pixels)[tc->tex_y
		* data->curr_texture->width + tc->tex_x];
	data->ray.tex_pos += data->ray.tex_step;
}

void	ft_color(t_cub3d *data, int x, int y)
{
	t_texture_colors	tc;

	tc.pix_buff = (uint32_t *)data->img->pixels;
	if (!tc.pix_buff || data->img->width != WIDTH
		|| data->img->height != HEIGHT)
		ft_clean(data, 0, 0, 0);
	if (y < data->ray.start_draw)
		tc.color = data->rgb_color_ceiling;
	else if (y > data->ray.draw_end)
		tc.color = data->rgb_color_flour;
	else if (!data->curr_texture || !data->curr_texture->pixels
		|| data->curr_texture->width == 0 || data->curr_texture->height == 0)
		tc.color = 0xFFFF00FF;
	else
	{
		// tc.color = 0xFFFF00FF;
		sample_texture(&tc, data);
	}
	tc.pix_buff[y * WIDTH + x] = tc.color;
}
