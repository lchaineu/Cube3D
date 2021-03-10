/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:52:36 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/08 13:23:34 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_color(t_params *params, t_color *color)
{
	if (color->red < 0 || color->red > 255)
		parsing_errors("red color non valid", params);
	if (color->green < 0 || color->green > 255)
		parsing_errors("green color non valid", params);
	if (color->blue < 0 || color->blue > 255)
		parsing_errors("blue color non valid", params);
}

void	check_textures(t_textures *textures, t_params *params)
{
	int i;
	int len;

	i = 0;
	len = (int)ft_strlen(textures->path);
	while (textures->path[i])
	{
		if (textures->path[i] == '\f' || textures->path[i] == '\t' ||
				textures->path[i] == '\n' ||
				textures->path[i] == '\r' || textures->path[i] == '\v'
				|| textures->path[i] == ' ')
			parsing_errors("not a good path for texture", params);
		i++;
	}
	if (textures->path[len - 4] != '.' || textures->path[len - 3] != 'x'
			|| textures->path[len - 2] != 'p' || textures->path[len - 1] != 'm')
		parsing_errors("not a good path for texture", params);
}

void	check_resolution(t_params *params)
{
	int x;
	int y;

	if (!(params->window.res))
		parsing_errors("Missing line resolution", params);
	mlx_get_screen_size(params->ptr, &x, &y);
	if (params->window.resolution.x_res < 1)
		parsing_errors("Window width can't be negative", params);
	if (params->window.resolution.y_res < 1)
		parsing_errors("Window height can't be negative", params);
	if (params->window.resolution.x_res > x)
		params->window.resolution.x_res = x;
	if (params->window.resolution.y_res > y)
		params->window.resolution.y_res = y;
}

void	data_parsing(t_params *params)
{
	char	*data;
	int		fd;

	if ((fd = open(params->mapfile, O_RDONLY)) == (-1))
		parsing_errors("Can't read file", params);
	while (get_next_line(fd, &data))
	{
		if (is_map_line(data))
			free(data);
		else
		{
			get_data(params, data);
			free(data);
		}
	}
	close(fd);
}
