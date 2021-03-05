/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:08:45 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/05 16:10:20 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_forward(t_params *params)
{
	if (params->map.map[(int)params->pos.y][(int)(params->pos.x +
	params->cam.dir.x * SPEED + (params->cam.dir.x > 0
	? MAXDIST : -MAXDIST))] != '1')
		params->pos.x += params->cam.dir.x * SPEED;
	if (params->map.map[(int)(params->pos.y + params->cam.dir.y * SPEED
	+ (params->cam.dir.y > 0 ? MAXDIST : -MAXDIST))]
	[(int)params->pos.x] != '1')
		params->pos.y += params->cam.dir.y * SPEED;
	params->event.w = 0;
	raycasting(params);
}

void	move_backward(t_params *params)
{
	if (params->map.map[(int)params->pos.y][(int)(params->pos.x - 
	params->cam.dir.x * SPEED - (params->cam.dir.x > 0
	? MAXDIST : -MAXDIST))] != '1')
		params->pos.x -= params->cam.dir.x * SPEED;
	if (params->map.map[(int)(params->pos.y - params->cam.dir.y * SPEED
	- (params->cam.dir.y > 0 ? MAXDIST : -MAXDIST))]
	[(int)params->pos.x] != '1')
		params->pos.y -= params->cam.dir.y * SPEED;
	params->event.s = 0;
	raycasting(params);
}

void	move_left(t_params *params)
{
	if (params->map.map[(int)params->pos.y][(int)(params->pos.x +
	params->cam.dir.y * SPEED + (params->cam.dir.y > 0
	? MAXDIST : -MAXDIST))] != '1')
		params->pos.x += params->cam.dir.y * SPEED;
	if (params->map.map[(int)(params->pos.y - params->cam.dir.x * SPEED
	- (params->cam.dir.x > 0 ? MAXDIST : -MAXDIST))]
	[(int)params->pos.x] != '1')
		params->pos.y -= params->cam.dir.x * SPEED;
	params->event.a = 0;
	raycasting(params);
}

void	move_right(t_params *params)

	if (params->map.map[(int)params->pos.y][(int)(params->pos.x -
	params->cam.dir.y * SPEED - (params->cam.dir.y > 0
	? MAXDIST : -MAXDIST))] != '1')
		params->pos.x -= params->cam.dir.y * SPEED;
	if (params->map.map[(int)(params->pos.y + params->cam.dir.x * SPEED
	+ (params->cam.dir.x > 0 ? MAXDIST : -MAXDIST))]
	[(int)params->pos.x] != '1')
		params->pos.y += params->cam.dir.x * SPEED;
	params->event.d = 0;
	raycasting(params);
}
