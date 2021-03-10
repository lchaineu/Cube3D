/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:50:59 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/10 13:21:31 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_mesures(t_params *params)
{
	params->cam.line_height = (int)((double)params->window.resolution.y_res
	/ params->cam.walldist);
	params->cam.draw_start = -params->cam.line_height /
	2 + params->window.resolution.y_res / 2;
	if (params->cam.draw_start < 0)
		params->cam.draw_start = 0;
	params->cam.draw_end = params->cam.line_height /
	2 + params->window.resolution.y_res / 2;
	if (params->cam.draw_end >= params->window.resolution.y_res)
		params->cam.draw_end = params->window.resolution.y_res - 1;
}

void	draw_wall(t_params *params)
{
	int	i;
	int	pix_pos;

	i = params->cam.draw_start;
	while (i < params->cam.draw_end)
	{
		pix_pos = params->cam.pix * params->image.bpp
		/ 8 + params->image.size_line * i;
		if (params->cam.compass == 0 && params->cam.dir.raydirx < 0)
			put_text_color(params, pix_pos, &params->window.west);
		else if (params->cam.compass == 0 && params->cam.dir.raydirx > 0)
		{
			put_text_color(params, pix_pos, &params->window.east);
		}
		else if (params->cam.compass == 1 && params->cam.dir.raydiry < 0)
		{
			put_text_color(params, pix_pos, &params->window.north);
		}
		else if (params->cam.compass == 1 && params->cam.dir.raydiry > 0)
		{
			put_text_color(params, pix_pos, &params->window.south);
		}
		i++;
	}
}

void	draw(t_params *params)
{
	int	i;
	int	pix_pos;

	i = 0;
	while (i < params->cam.draw_start)
	{
		pix_pos = params->cam.pix * params->image.bpp
		/ 8 + params->image.size_line * i;
		pix_color(params, pix_pos, params->window.ceiling);
		i++;
	}
	draw_wall(params);
	i = params->cam.draw_end;
	while (i < params->window.resolution.y_res)
	{
		pix_pos = params->cam.pix * params->image.bpp
		/ 8 + params->image.size_line * i;
		pix_color(params, pix_pos, params->window.floor);
		i++;
	}
}
