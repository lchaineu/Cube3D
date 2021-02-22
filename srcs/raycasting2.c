#include "cub.h"

void	draw_mesures(t_params *params)
{
	params->cam.line_height = (int)((double)params->window.resolution.y_res
									 / params->cam.walldist);
	params->cam.draw_start = -params->cam.line_height /
							 2 + params->window.resolution.y_res / 2;
	if (params->cam.draw_start < 0)
		params->cam.draw_start = 0;
	params->cam.draw_end = params->cam.line_height /
							 2 + params->window.resolution.y_res / 2;
	if (params->cam.draw_end >= params->window.resolution.y_res)
		params->cam.draw_end = params->window.resolution.y_res - 1;
}

void	stock_good_texture(t_params *params, t_textures *texture)
{
	texture->textX = (int)(params->cam.wallX * (double)texture->width);
	texture->textX = texture->width - texture->textX - 1;
	texture->step = 1.0 * (double)texture->height / params->cam.line_height;
	texture->textY = (params->cam.draw_start - params->window.resolution.y_res / 2
						+ params->cam.line_height / 2) * texture->step;
}

void	get_texture_coordinate(t_params *params)
{
	if (params->cam.compass == 0 && params->cam.dir.raydirX < 0)
	{
		stock_good_texture(params, &params->window.west);
	}
	else if (params->cam.compass == 0 && params->cam.dir.raydirX > 0)
	{
		stock_good_texture(params, &params->window.east);
	}
	else if (params->cam.compass == 1 && params->cam.dir.raydirY < 0)
	{
		stock_good_texture(params, &params->window.north);
	}
	else if (params->cam.compass == 1 && params->cam.dir.raydirY > 0)
	{
		stock_good_texture(params, &params->window.south);
	}
}

void	get_wall_x(t_params *params)
{
	if (params->cam.compass == 0)
	{
		params->cam.wallX = params->pos.y + params->cam.walldist
							*  params->cam.dir.raydirY;
	}
	else
	{
		params->cam.wallX = params->pos.x + params->cam.walldist
							*  params->cam.dir.raydirX;
	}
	params->cam.wallX -= floor(params->cam.wallX);
	get_texture_coordinate(params);
}

void	draw(t_params *params)
{
	int	i;
	int	pix_pos;

	i = 0;
	while (i < params->cam.draw_start)
	{
		pix_pos = params->cam.pix * params->image.bpp
		/ 8 + params->image.size_line * i;
		pix_color(params, pix_pos, params->window.ceiling);
		i++;
	}
	draw_wall(params);
	i = params->cam.draw_end;
	while (i < params->window.resolution.y_res)
	{
		pix_pos = params->cam.pix * params->image.bpp
		/ 8 + params->image.size_line * i;
		pix_color(params, pix_pos, params->window.floor);
		i++;
	}
}