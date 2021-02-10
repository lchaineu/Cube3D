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

void		save_map(t_map *map, char *mapfile)
{
	int		fd;
	int		i;
	char	*map_data;

	i = 0;
	if ((fd = open(mapfile, O_RDONLY)) == (-1))
		ft_printf("Error: Can't read file\n");
	while (get_next_line(fd, &map_data))
	{
		if (is_map_line(map_data) && !(is_empty_line(map_data)))
		{
			map->map[i] = map_data;
			i++;
		}
	}
	if (is_map_line(map_data) && !(is_empty_line(map_data)))
	{
		map->map[i]= map_data;
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
		ft_printf("Error: Can't read file\n");
	while (get_next_line(fd, &map_data))
	{
		if (is_map_line(map_data) && !(is_empty_line(map_data)))
		{
			i++;
		}
		free(map_data);
	}
	if (is_map_line(map_data) && !(is_empty_line(map_data)))
			i++;
	free(map_data);
	close(fd);
	if (!(params->map.map = (char**)malloc(sizeof(char *) * (i + 1))))
		ft_printf("Error: can't malloc map\n");
	params->map.map[i] = NULL;
	save_map(&params->map, params->mapfile);
	search_pos(params->map, params);
}
