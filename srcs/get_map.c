/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:32:18 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/10 14:23:08 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		save_map(t_params *params, char *mapfile)
{
	int		fd;
	int		i;
	char	*map_data;

	i = 0;
	map_data = NULL;
	if ((fd = open(mapfile, O_RDONLY)) == (-1))
		parsing_errors("Can't read file", params);
	keep_saving_or_not(params, &map_data, &i, fd);
	check_invalid_char(params, map_data);
	close(fd);
}

void		parse_map(t_params *params)
{
	if (!(is_a_good_map(params)))
		parsing_errors("Map isn't closed or is not valid", params);
	search_pos(params->map, params);
	if (params->starting_point == 0)
		parsing_errors("You must add a starting point to your map", params);
}

void		get_map(t_params *params)
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
		if (!(is_map_line(map_data)) && i)
		{
			finish_reading(params);
			break ;
		}
		free(map_data);
	}
	if (is_map_line(map_data) && !(is_empty_line(map_data)))
		i++;
	free(map_data);
	close(fd);
	malloc_map(params, i);
	save_map(params, params->mapfile);
	parse_map(params);
}
