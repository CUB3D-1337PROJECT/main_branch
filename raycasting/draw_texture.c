/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:51:40 by slakhrou          #+#    #+#             */
/*   Updated: 2025/11/26 18:05:24 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	texture_sides(t_cub3d *data)
{
	if (data->ray.side == 1)
	{
		if (data->ray.dir_y > 0)
			data->cur_text = data->texts->text_so;
		else
			data->cur_text = data->texts->text_no;
	}
	else
	{
		if (data->ray.dir_x > 0)
			data->cur_text = data->texts->text_ea;
		else
			data->cur_text = data->texts->text_we;
	}
}

static void	draw_texture(t_texture_colors *tc, t_cub3d *data)
{
	int	text_colors;

	tc->tex_y = (int)(data->ray.tex_pos);
	if (tc->tex_y < 0)
		tc->tex_y = 0;
	if (tc->tex_y >= (int)data->cur_text->height)
		tc->tex_y = (int)data->cur_text->height - 1;
	tc->tex_x = data->ray.tex_x;
	if (tc->tex_x < 0)
		tc->tex_x = 0;
	if (tc->tex_x >= (int)data->cur_text->width)
		tc->tex_x = (int)data->cur_text->width - 1;
	text_colors = tc->tex_y * data->cur_text->width + tc->tex_x;
	tc->color = ((uint32_t *)data->cur_text->pixels)[text_colors];
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
	else if (!data->cur_text || !data->cur_text->pixels
		|| data->cur_text->width == 0 || data->cur_text->height == 0)
		tc.color = 0x00FF00FF;
	else
	{
		draw_texture(&tc, data);
	}
	tc.pix_buff[y * WIDTH + x] = tc.color;
}
