#include "cub.h"

int		count_sprites(t_params *params)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (params->map.map[y] != NULL)
	{
		x = 0;
		while (params->map.map[y][x])
		{
			if (params->map.map[y][x] == '2')
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

void	set_sprites(t_params *params)
{
	params->sprite.sprites_num = count_sprites(params);
	if (!(params->sprite.tab = malloc(sizeof(t_vect) * params->sprite.sprites_num)))
		errors("Can't malloc sprites", params);
	if (!(params->sprite.order = malloc(sizeof(int) * params->sprite.sprites_num)))
		errors("Can't malloc the sprites order", params);
	if (!(params->sprite.dist = malloc(sizeof(double) * params->sprite.sprites_num)))
		errors("Can't malloc the sprites distances", params);
}

void	get_sprites_distances(t_params *params, t_vect pos)
{
	int x;
	int y;
	int i;

	i = 0;
	while (i < params->sprite.sprites_num)
	{
		x = params->sprite.tab[i].x;
		y = params->sprite.tab[i].y;
		params->sprite.dist[i] = ((pos.x - x) * (pos.x - x) + (pos.y - y) * (pos.y - y));
		i++; 
	}
}

void	switch_sprites(t_params *params)
{
	int i;
	int buff;
	int modif;

	i = 0;
	modif = 1;
	get_sprites_distances(params, params->pos);
	while (modif)
	{
		modif = 0;
		i = 0;
		if (params->sprite.dist[params->sprite.order[i - 1]] 
		< params->sprite.dist[params->sprite.order[i]])
		{
			buff = params->sprite.order[i];
			params->sprite.order[i] = params->sprite.order[i - 1];
			params->sprite.order[i - 1] = buff;
			modif = 1;
		}
		i++;
	}
}

void	set_sprites_values(t_params *params, t_vect tab)
{
	params->sprite.coords.x = tab.x - params->pos.x;
	params->sprite.coords.y = tab.y - params->pos.y;
	params->sprite.invDet = 1.0 / (params->cam.plane.x * params->cam.dir.y
	- params->cam.dir.x * params->cam.plane.y);
	params->sprite.transform.x = params->sprite.invDet * (params->cam.dir.y
	* params->sprite.coords.x - params->cam.dir.x * params->sprite.coords.y);
	params->sprite.transform.y = params->sprite.invDet * (-params->cam.plane.y *
	params->sprite.coords.x + params->cam.plane.x * params->sprite.coords.y);

}

void	sprites(t_params *params)
{
	int i;

	i = 0;
	switch_sprites(params);
	while (i < params->sprite.sprites_num)
	{
		set_sprites_values(params, params->sprite.tab[params->sprite.order[i]]);
		i++;
	}
}