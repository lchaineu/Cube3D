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

void	errors(char *error, t_params *params)
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
		free(params->window.west.path);
	map_destroyer(&params->map);
	ft_printf("Error: %s\n", error);
	exit(EXIT_FAILURE);
}