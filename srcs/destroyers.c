/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:34:38 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/08 14:46:22 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_destroyer(t_map *map)
{
	int i;

	i = 0;
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

void	images_destroyer(t_params *params)
{
	if (params->image.ptr)
		mlx_destroy_image(params->ptr, params->image.ptr);
	if (params->window.north.img.ptr)
		mlx_destroy_image(params->ptr, params->window.north.img.ptr);
	if (params->window.south.img.ptr)
		mlx_destroy_image(params->ptr, params->window.south.img.ptr);
	if (params->window.east.img.ptr)
		mlx_destroy_image(params->ptr, params->window.east.img.ptr);
	if (params->window.west.img.ptr)
		mlx_destroy_image(params->ptr, params->window.west.img.ptr);
	if (params->window.ptr)
		mlx_destroy_window(params->ptr, params->window.ptr);
}
