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

void	sprites_positions(t_params *params)
{
	int	i;
	int	x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (params->map.map[y])
	{
		x = 0;
		while (params->map.map[y][x])
		{
			if (params->map.map[y][x] == '2')
			{
				params->sprite.tab[i].x = x + 0.5;
				params->sprite.tab[i].y = y + 0.5;
				params->sprite.order[i] = i;
				i++;
			}
			x++;
		}
		y++;
	}
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
	sprites_positions(params);
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
		i = 1;
		while (i < params->sprite.sprites_num)
		{
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
}

void	calculate_more_sprites_values(t_params *params)
{
	params->sprite.startY = -params->sprite.height / 2 + params->window.resolution.y_res / 2;
	if (params->sprite.startY < 0)
		params->sprite.startY = 0;
	params->sprite.endY = params->sprite.height / 2 + params->window.resolution.y_res / 2;
	if (params->sprite.endY >= params->window.resolution.y_res)
		params->sprite.endY = params->window.resolution.y_res - 1;
	params->sprite.width = abs((int)(params->window.resolution.y_res /
	params->sprite.transform.y));
	params->sprite.startX = -params->sprite.width / 2 + params->sprite.center_stripe;
	if (params->sprite.startX < 0)
		params->sprite.startX = 0;
	params->sprite.endX = params->sprite.width / 2 + params->sprite.center_stripe;
	if (params->sprite.endX >= params->window.resolution.x_res)
		params->sprite.endX = params->window.resolution.x_res - 1;
	params->sprite.stripe = params->sprite.startX;
}

void	calculate_sprites_values(t_params *params, t_vect tab)
{
	params->sprite.coords.x = tab.x - params->pos.x;
	params->sprite.coords.y = tab.y - params->pos.y;
	params->sprite.invDet = 1.0 / (params->cam.plane.x * params->cam.dir.y
	- params->cam.dir.x * params->cam.plane.y);
	params->sprite.transform.x = params->sprite.invDet * (params->cam.dir.y
	* params->sprite.coords.x - params->cam.dir.x * params->sprite.coords.y);
	params->sprite.transform.y = params->sprite.invDet * (-params->cam.plane.y *
	params->sprite.coords.x + params->cam.plane.x * params->sprite.coords.y);
	params->sprite.center_stripe = (int)((params->window.resolution.x_res / 2) * (1
	+ params->sprite.transform.x / params->sprite.transform.y));
	params->sprite.height = abs((int)(params->window.resolution.y_res /
	params->sprite.transform.y));
	calculate_more_sprites_values(params);
}

void	draw_sprites_bis(t_params *params)
{
	int	y;
	int	pix_pos;

	get_sprites_texture(params);
	y = params->sprite.startY;
	while (y < params->sprite.endY)
	{
		pix_pos = params->sprite.stripe * params->image.bpp
		/ 8 + params->image.size_line * y;
		put_sprites_text(params, pix_pos, &params->sprite.textures);
		y++;
	}
}

void	draw_sprites(t_params *params)
{
	while (params->sprite.stripe < params->sprite.endX)
	{
		if (params->sprite.transform.y > 0 && params->sprite.stripe > 0
		&& params->sprite.stripe < params->window.resolution.x_res
		&& params->sprite.transform.y < params->cam.dist_buffer[params->sprite.stripe])
			draw_sprites_bis(params);
	params->sprite.stripe++;
	}
}

void	sprites(t_params *params)
{
	int i;

	i = 0;
	switch_sprites(params);
	while (i < params->sprite.sprites_num)
	{
		calculate_sprites_values(params, params->sprite.tab[params->sprite.order[i]]);
		draw_sprites(params);
		i++;
	}
}
