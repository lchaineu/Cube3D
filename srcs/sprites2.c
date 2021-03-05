/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:58:33 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/05 16:19:50 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_sprites_texture(t_params *params)
{
	params->sprite.textures.textx = (int)((params->sprite.stripe +
	(double)params->sprite.width / 2 -
	(double)params->sprite.center_stripe) * (double)params->sprite.textures.width /
	(double)params->sprite.width);
	params->sprite.textures.step = 1.0 * params->sprite.textures.height /
	params->sprite.height;
	params->sprite.textures.texty = ((double)params->sprite.starty -
	(double)params->window.resolution.y_res / 2 + (double)params->sprite.height / 2)
	* params->sprite.textures.step;
	params->sprite.textures.texty-= params->sprite.textures.step;
}

void	put_sprites_text(t_params *params, int pix_pos, t_textures * text)
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
