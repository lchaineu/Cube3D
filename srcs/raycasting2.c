/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:41:12 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/08 13:54:59 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	stock_good_texture(t_params *params, t_textures *texture)
{
	texture->textx = (int)(params->cam.wallx * (double)texture->width);
	texture->textx = texture->width - texture->textx - 1;
	texture->step = 1.0 * (double)texture->height / params->cam.line_height;
	texture->texty = (params->cam.draw_start -
	params->window.resolution.y_res / 2
	+ params->cam.line_height / 2) * texture->step;
}

void	get_texture_coordinate(t_params *params)
{
	if (params->cam.compass == 0 && params->cam.dir.raydirx < 0)
	{
		stock_good_texture(params, &params->window.west);
	}
	else if (params->cam.compass == 0 && params->cam.dir.raydirx > 0)
	{
		stock_good_texture(params, &params->window.east);
	}
	else if (params->cam.compass == 1 && params->cam.dir.raydiry < 0)
	{
		stock_good_texture(params, &params->window.north);
	}
	else if (params->cam.compass == 1 && params->cam.dir.raydiry > 0)
	{
		stock_good_texture(params, &params->window.south);
	}
}

void	get_wall_x(t_params *params)
{
	if (params->cam.compass == 0)
	{
		params->cam.wallx = params->pos.y + params->cam.walldist
		* params->cam.dir.raydiry;
	}
	else
	{
		params->cam.wallx = params->pos.x + params->cam.walldist
		* params->cam.dir.raydirx;
	}
	params->cam.wallx -= floor(params->cam.wallx);
	get_texture_coordinate(params);
}

void	pix_color(t_params *params, int pix_pos, t_color color)
{
	params->image.info[pix_pos] = color.blue;
	params->image.info[pix_pos + 1] = color.green;
	params->image.info[pix_pos + 2] = color.red;
}

void	put_text_color(t_params *params, int pix_pos, t_textures *texture)
{
	int pixel_pos;

	texture->texty += texture->step;
	pixel_pos = texture->textx * texture->img.bpp
	/ 8 + texture->img.size_line * (int)texture->texty;
	params->image.info[pix_pos] =
	texture->img.info[pixel_pos];
	params->image.info[pix_pos + 1] =
	texture->img.info[pixel_pos + 1];
	params->image.info[pix_pos + 2] =
	texture->img.info[pixel_pos + 2];
}
