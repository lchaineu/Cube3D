/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:57:16 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/10 14:25:19 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		check_invalid_char(t_params *params, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!is_char_in_str(" 012NSEW", str[i]))
		{
			free(str);
			parsing_errors("map invalid character", params);
		}
		i++;
	}
}

void		finish_reading(t_params *params)
{
	int		fd;
	char	*map_data;

	if ((fd = open(params->mapfile, O_RDONLY)) == (-1))
		parsing_errors("Can't read file", params);
	while (get_next_line(fd, &map_data))
		free(map_data);
	free(map_data);
	close(fd);
}

void		malloc_map(t_params *params, int i)
{
	if (!(params->map.map = (char**)malloc(sizeof(char *) * (i + 1))))
		parsing_errors("Can't malloc map", params);
	params->map.map[i] = NULL;
}

void		keep_saving_or_not(t_params *params, 
			char **map_data, int *i, int fd)
{
	while (get_next_line(fd, map_data))
	{
		if (is_map_line(*map_data) && !(is_empty_line(*map_data)))
		{
			params->map.map[*i] = *map_data;
			(*i)++;
		}
		if (!(is_map_line(*map_data)) && *i)
		{
			check_invalid_char(params, *map_data);
			break ;
		}
	}
	if (is_map_line(*map_data) && !(is_empty_line(*map_data)))
	{
		params->map.map[*i] = *map_data;
		(*i)++;
	}
}
