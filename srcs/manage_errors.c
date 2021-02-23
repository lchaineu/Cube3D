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

void	parsing_errors(char *error, t_params *params)
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
	//free_variables
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
		free(params->window.west.path);
	map_destroyer(&params->map);
	//free_variables
	images_destroyer(params);
	exit(EXIT_SUCCESS);
}
