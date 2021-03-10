/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organise_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:58:28 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/08 12:44:28 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		count_sprites(t_params *params)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (params->map.map[y] != NULL)
	{
		x = 0;
		while (params->map.map[y][x])
		{
			if (params->map.map[y][x] == '2')
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

void	sprites_positions(t_params *params)
{
	int	i;
	int	x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (params->map.map[y])
	{
		x = 0;
		while (params->map.map[y][x])
		{
			if (params->map.map[y][x] == '2')
			{
				params->sprite.tab[i].x = x + 0.5;
				params->sprite.tab[i].y = y + 0.5;
				params->sprite.order[i] = i;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	set_sprites(t_params *params)
{
	params->sprite.sprites_num = count_sprites(params);
	if (!(params->sprite.tab = malloc(sizeof(t_vect)
	* params->sprite.sprites_num)))
		errors("Can't malloc sprites", params);
	if (!(params->sprite.order = malloc(sizeof(int)
	* params->sprite.sprites_num)))
		errors("Can't malloc the sprites order", params);
	if (!(params->sprite.dist = malloc(sizeof(double)
	* params->sprite.sprites_num)))
		errors("Can't malloc the sprites distances", params);
	sprites_positions(params);
}

void	get_sprites_distances(t_params *params, t_vect pos)
{
	int x;
	int y;
	int i;

	i = 0;
	while (i < params->sprite.sprites_num)
	{
		x = params->sprite.tab[i].x;
		y = params->sprite.tab[i].y;
		params->sprite.dist[i] = ((pos.x - x) * (pos.x - x)
		+ (pos.y - y) * (pos.y - y));
		i++;
	}
}

void	switch_sprites(t_params *params)
{
	int i;
	int buff;
	int modif;

	i = 0;
	modif = 1;
	get_sprites_distances(params, params->pos);
	while (modif)
	{
		modif = 0;
		i = 1;
		while (i < params->sprite.sprites_num)
		{
			if (params->sprite.dist[params->sprite.order[i - 1]]
			< params->sprite.dist[params->sprite.order[i]])
			{
				buff = params->sprite.order[i];
				params->sprite.order[i] = params->sprite.order[i - 1];
				params->sprite.order[i - 1] = buff;
				modif = 1;
			}
			i++;
		}
	}
}
