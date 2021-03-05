/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:59:19 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/05 16:03:51 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_cub_val(t_params *params)
{
	params->image.ptr = NULL;
	params->window.north.img.ptr = NULL;
	params->window.south.img.ptr = NULL;
	params->window.east.img.ptr = NULL;
	params->window.west.img.ptr = NULL;
	params->sprite.textures.img.ptr = NULL;
	params->event.w = 0;
	params->event.s = 0;
	params->event.a = 0;
	params->event.d = 0;
	params->event.right_arrow = 0;
	params->event.left_arrow = 0;
	params->sprite.order = NULL;
	params->sprite.tab = NULL;
	params->sprite.dist = NULL;
}

void	init_textures(t_params *params)
{
	if (!(params->window.north.img.info = (unsigned char*)mlx_get_data_addr(
	params->window.north.img.ptr, &params->window.north.img.bpp,
	&params->window.north.img.size_line, &params->window.north.img.endian)))
		errors("Can't get north texture info", params);
	if (!(params->window.south.img.info = (unsigned char*)mlx_get_data_addr(
	params->window.south.img.ptr, &params->window.south.img.bpp,
	&params->window.south.img.size_line, &params->window.south.img.endian)))
		errors("Can't get south texture info", params);
	if (!(params->window.east.img.info = (unsigned char*)mlx_get_data_addr(
	params->window.east.img.ptr, &params->window.east.img.bpp,
	&params->window.east.img.size_line, &params->window.east.img.endian)))
		errors("Can't get east texture info", params);
	if (!(params->window.west.img.info = (unsigned char*)mlx_get_data_addr(
	params->window.west.img.ptr, &params->window.west.img.bpp,
	&params->window.west.img.size_line, &params->window.west.img.endian)))
		errors("Can't get west texture info", params);
	if (!(params->sprite.textures.img.info = (unsigned char*)mlx_get_data_addr(
	params->sprite.textures.img.ptr, &params->sprite.textures.img.bpp,
	&params->sprite.textures.img.size_line,
	&params->sprite.textures.img.endian)))
		errors("Can't get sprites texture info", params);
}

void	get_textures(t_params *params)
{
	if (!(params->window.north.img.ptr =
			mlx_xpm_file_to_image(params->ptr, params->window.north.path,
			&params->window.north.width, &params->window.north.height)))
		errors("Can't load north texture", params);
	if (!(params->window.south.img.ptr =
			mlx_xpm_file_to_image(params->ptr, params->window.south.path,
			&params->window.south.width, &params->window.south.height)))
		errors("Can't load south texture", params);
	if (!(params->window.east.img.ptr =
			mlx_xpm_file_to_image(params->ptr, params->window.east.path,
			&params->window.east.width, &params->window.east.height)))
		errors("Can't load east texture", params);
	if (!(params->window.west.img.ptr =
			mlx_xpm_file_to_image(params->ptr, params->window.west.path,
			&params->window.west.width, &params->window.west.height)))
		errors("Can't load west texture", params);
	if (!(params->sprite.textures.img.ptr =
			mlx_xpm_file_to_image(params->ptr, params->sprite.textures.path,
			&params->sprite.textures.width, &params->sprite.textures.height)))
		errors("Can't load sprites texture", params);
	init_textures(params);
}

void	create_cub(t_params *params)
{
	set_cub_val(params);
	if (!(params->window.ptr = mlx_new_window(params->ptr,
			params->window.resolution.x_res,
			params->window.resolution.y_res, "Cub3D")))
		errors("Can't create window", params);
	if (!(params->image.ptr = mlx_new_image(params->ptr,
			params->window.resolution.x_res,
			params->window.resolution.y_res)))
		errors("Can't create image", params);
	if (!(params->image.info = (unsigned char *)
	mlx_get_data_addr(params->image.ptr, &params->image.bpp,
	&params->image.size_line, &params->image.endian)))
		errors("Can't get image data", params);
	get_textures(params);
	set_sprites(params);
	raycasting(params);
}

void	set_parsing_val(t_params *params)
{
	params->window.north.path = NULL;
	params->window.south.path = NULL;
	params->window.east.path = NULL;
	params->window.west.path = NULL;
	params->sprite.textures.path = NULL;
	params->map.map = NULL;
	params->window.floor.blue = 0;
	params->window.floor.green = 0;
	params->window.floor.red = 0;
	params->window.ceiling.blue = 0;
	params->window.ceiling.green = 0;
	params->window.ceiling.red = 0;
	params->window.resolution.x_res = 0;
	params->window.resolution.y_res = 0;
	params->cam.dist_buffer = NULL;
	params->save = 0;
}
