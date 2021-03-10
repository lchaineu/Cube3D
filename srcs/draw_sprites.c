/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:40:00 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/08 13:22:11 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_sprites_text(t_params *params, int pix_pos, t_textures *text)
{
	int				pix_pos_text;
	unsigned int	color;

	text->texty += text->step;
	pix_pos_text = text->textx * text->img.bpp
	/ 8 + text->img.size_line * (int)text->texty;
	color = text->img.info[pix_pos_text] + 256 *
	text->img.info[pix_pos_text + 1] + 256 * 256
	* text->img.info[pix_pos_text + 2];
	if ((color & 0x00FFFFFF) != 0)
	{
		params->image.info[pix_pos] =
		text->img.info[pix_pos_text];
		params->image.info[pix_pos + 1] =
		text->img.info[pix_pos_text + 1];
		params->image.info[pix_pos + 2] =
		text->img.info[pix_pos_text + 2];
	}
}

void	draw_sprites_bis(t_params *params)
{
	int	y;
	int	pix_pos;

	get_sprites_texture(params);
	y = params->sprite.starty;
	while (y < params->sprite.endy)
	{
		pix_pos = params->sprite.stripe * params->image.bpp
		/ 8 + params->image.size_line * y;
		put_sprites_text(params, pix_pos, &params->sprite.textures);
		y++;
	}
}

void	draw_sprites(t_params *params)
{
	while (params->sprite.stripe < params->sprite.endx)
	{
		if (params->sprite.transform.y > 0 && params->sprite.stripe > 0
		&& params->sprite.stripe < params->window.resolution.x_res
		&& params->sprite.transform.y <
		params->cam.dist_buffer[params->sprite.stripe])
			draw_sprites_bis(params);
		params->sprite.stripe++;
	}
}
