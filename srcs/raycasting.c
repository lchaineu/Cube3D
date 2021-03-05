/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:51:30 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/05 16:15:46 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		get_cam_values(t_params *params)
{
	params->cam.hit = 0;
	params->cam.cam_x = 2 * params->cam.pix /
				(double)params->window.resolution.x_res - 1;
	params->cam.dir.raydirx = params->cam.dir.x +
				params->cam.plane.x * params->cam.cam_x;
	params->cam.dir.raydiry = params->cam.dir.y +
				params->cam.plane.y * params->cam.cam_x;
	params->map.map_pos.x = (int)params->pos.x;
	params->map.map_pos.y = (int)params->pos.y;
	params->cam.deltadist.x = fabs(1 / params->cam.dir.raydirx);
	params->cam.deltadist.y = fabs(1 / params->cam.dir.raydiry);
}

static void		get_side_dist(t_params *params)
{
	if (params->cam.dir.raydirx < 0)
	{
		params->cam.step.x = -1;
		params->cam.sidedist.x = (params->pos.x
		- params->map.map_pos.x) * params->cam.deltadist.x;
	}
	else
	{
		params->cam.step.x = 1;
		params->cam.sidedist.x = (params->map.map_pos.x
		+ 1.0 - params->pos.x) * params->cam.deltadist.x;
	}
	if (params->cam.dir.raydiry < 0)
	{
		params->cam.step.y = -1;
		params->cam.sidedist.y = (params->pos.y
		- params->map.map_pos.y) * params->cam.deltadist.y;
	}
	else
	{
		params->cam.step.y = 1;
		params->cam.sidedist.y = (params->map.map_pos.y
		+ 1.0 - params->pos.y) * params->cam.deltadist.y;
	}
}

static void		get_hit(t_params *params)
{
	while (params->cam.hit == 0)
	{
		if (params->cam.sidedist.x < params->cam.sidedist.y)
		{
			params->cam.sidedist.x += params->cam.deltadist.x;
			params->map.map_pos.x += params->cam.step.x;
			params->cam.compass = 0;
		}
		else
		{
			params->cam.sidedist.y += params->cam.deltadist.y;
			params->map.map_pos.y += params->cam.step.y;
			params->cam.compass = 1;
		}
		if (params->map.map[(int)params->map.map_pos.y]
				[(int)params->map.map_pos.x] == '1')
			params->cam.hit = 1;
	}
}

static void		get_hit_dist(t_params *params)
{
	if (params->cam.compass == 0)
	{
		params->cam.walldist = (params->map.map_pos.x - params->pos.x +
		(1 - (int)params->cam.step.x) / 2) / params->cam.dir.raydirx;
	}
	else
	{
		params->cam.walldist = (params->map.map_pos.y - params->pos.y +
		(1 - (int)params->cam.step.y) / 2) / params->cam.dir.raydiry;
	}
	params->cam.dist_buffer[params->cam.pix] = params->cam.walldist;
}

void			raycasting(t_params *params)
{
	params->cam.pix = 0;
	while (params->cam.pix < params->window.resolution.x_res)
	{
		get_cam_values(params);
		get_side_dist(params);
		get_hit(params);
		get_hit_dist(params);
		draw_mesures(params);
		get_wall_x(params);
		draw(params);
		params->cam.pix++;
	}
	sprites(params);
	mlx_put_image_to_window(params->ptr,
	params->window.ptr, params->image.ptr, 0, 0);
}
