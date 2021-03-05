/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:07:31 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/05 16:08:40 by lchaineu         ###   ########.fr       */
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
	mlx_destroy_window(params->ptr, params->window.ptr);
}

void	free_variables(t_params *params)
{
	if (params->sprite.tab)
		free(params->sprite.tab);
	if (params->sprite.order)
		free(params->sprite.order);
	if (params->sprite.dist)
		free(params->sprite.dist);
}

void	parsing_errors(char *error, t_params *params)
{
	free(params->mapfile);
	if (params->window.north.path)
		free(params->window.north.path);
	if (params->window.south.path)
		free(params->window.south.path);
	if (params->window.east.path)
		free(params->window.east.path);
	if (params->window.west.path)
		free(params->window.west.path);
	if (params->sprite.textures.path)
		free(params->sprite.textures.path);
	if (params->cam.dist_buffer)
		free(params->cam.dist_buffer);
	map_destroyer(&params->map);
	ft_printf("Error: %s\n", error);
	exit(EXIT_FAILURE);
}

void	errors(char *error, t_params *params)
{
	free(params->mapfile);
	if (params->window.north.path)
		free(params->window.north.path);
	if (params->window.south.path)
		free(params->window.south.path);
	if (params->window.east.path)
		free(params->window.east.path);
	if (params->window.west.path)
		free(params->window.west.path);
	if (params->sprite.textures.path)
		free(params->sprite.textures.path);
	if (params->cam.dist_buffer)
		free(params->cam.dist_buffer);
	free_variables(params);
	images_destroyer(params);
	map_destroyer(&params->map);
	ft_printf("Error: %s\n", error);
	exit(EXIT_FAILURE);
}

void	do_exit(t_params *params)
{
	if (params->mapfile)
		free(params->mapfile);
	if (params->window.north.path)
		free(params->window.north.path);
	if (params->window.south.path)
		free(params->window.south.path);
	if (params->window.east.path)
		free(params->window.east.path);
	if (params->window.west.path)
		fre(params->window.west.path);
	map_destroyer(&params->map);
	free_variables(params);
	images_destroyer(params);
	exit(EXIT_SUCCESS);
}
