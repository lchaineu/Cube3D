/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:58:33 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/08 12:46:53 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_sprites_texture(t_params *params)
{
	params->sprite.textures.textx = (int)((params->sprite.stripe +
	(double)params->sprite.width / 2 -
	(double)params->sprite.center_stripe) *
	(double)params->sprite.textures.width /
	(double)params->sprite.width);
	params->sprite.textures.step = 1.0 * params->sprite.textures.height /
	params->sprite.height;
	params->sprite.textures.texty = ((double)params->sprite.starty -
	(double)params->window.resolution.y_res / 2 +
	(double)params->sprite.height / 2)
	* params->sprite.textures.step;
	params->sprite.textures.texty -= params->sprite.textures.step;
}

void	calculate_more_sprites_values(t_params *params)
{
	params->sprite.starty = -params->sprite.height / 2 +
	params->window.resolution.y_res / 2;
	if (params->sprite.starty < 0)
		params->sprite.starty = 0;
	params->sprite.endy = params->sprite.height / 2 +
	params->window.resolution.y_res / 2;
	if (params->sprite.endy >= params->window.resolution.y_res)
		params->sprite.endy = params->window.resolution.y_res - 1;
	params->sprite.width = abs((int)(params->window.resolution.y_res /
	params->sprite.transform.y));
	params->sprite.startx = -params->sprite.width / 2 +
	params->sprite.center_stripe;
	if (params->sprite.startx < 0)
		params->sprite.startx = 0;
	params->sprite.endx = params->sprite.width / 2 +
	params->sprite.center_stripe;
	if (params->sprite.endx >= params->window.resolution.x_res)
		params->sprite.endx = params->window.resolution.x_res - 1;
	params->sprite.stripe = params->sprite.startx;
}

void	calculate_sprites_values(t_params *params, t_vect tab)
{
	params->sprite.coords.x = tab.x - params->pos.x;
	params->sprite.coords.y = tab.y - params->pos.y;
	params->sprite.inv_det = 1.0 / (params->cam.plane.x * params->cam.dir.y
	- params->cam.dir.x * params->cam.plane.y);
	params->sprite.transform.x = params->sprite.inv_det * (params->cam.dir.y
	* params->sprite.coords.x - params->cam.dir.x * params->sprite.coords.y);
	params->sprite.transform.y = params->sprite.inv_det *
	(-params->cam.plane.y *
	params->sprite.coords.x + params->cam.plane.x * params->sprite.coords.y);
	params->sprite.center_stripe = (int)((params->window.resolution.x_res / 2)
	* (1 + params->sprite.transform.x / params->sprite.transform.y));
	params->sprite.height = abs((int)(params->window.resolution.y_res /
	params->sprite.transform.y));
	calculate_more_sprites_values(params);
}

void	sprites(t_params *params)
{
	int i;

	i = 0;
	switch_sprites(params);
	while (i < params->sprite.sprites_num)
	{
		calculate_sprites_values(params,
		params->sprite.tab[params->sprite.order[i]]);
		draw_sprites(params);
		i++;
	}
}
