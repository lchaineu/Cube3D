/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:55:58 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/05 16:05:58 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		search_pos(t_map map, t_params *params)
{
	int		x;
	int		y;

	y = 0;
	while (map.map[y] != NULL)
	{
		x = 0;
		while (map.map[y][x])
		{
			if (search_string(map.map[y][x], "NSEW"))
			{
				get_pos(params, x, y, map.map[y][x]);
			}
			x++;
		}
		y++;
	}
}

void		save_map(t_params *params, char *mapfile)
{
	int		fd;
	int		i;
	char	*map_data;

	i = 0;
	if ((fd = open(mapfile, O_RDONLY)) == (-1))
		parsing_errors("Can't read file", params);
	while (get_next_line(fd, &map_data))
	{
		if (is_map_line(map_data) && !(is_empty_line(map_data)))
		{
			params->map.map[i] = map_data;
			i++;
		}
	}
	if (is_map_line(map_data) && !(is_empty_line(map_data)))
	{
		params->map.map[i] = map_data;
		i++;
	}
	close(fd);
}

void		malloc_map(t_params *params)
{
	int		fd;
	int		i;
	char	*map_data;

	i = 0;
	if ((fd = open(params->mapfile, O_RDONLY)) == (-1))
		parsing_errors("Can't read file", params);
	while (get_next_line(fd, &map_data))
	{
		if (is_map_line(map_data) && !(is_empty_line(map_data)))
			i++;
		free(map_data);
	}
	if (is_map_line(map_data) && !(is_empty_line(map_data)))
			i++;
	free(map_data);
	close(fd);
	if (!(params->map.map = (char**)malloc(sizeof(char *) * (i + 1))))
		parsing_errors("Can't malloc map", params);
	params->map.map[i] = NULL;
	save_map(params, params->mapfile);
	if (!(is_a_good_map(params->map.map)))
		parsing_errors("Map isn't closed or is not valid", params);
	search_pos(params->map, params);
}
