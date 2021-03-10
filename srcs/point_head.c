/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:20:14 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/08 13:20:15 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	point_left(t_params *params)
{
	double	dir_x_bis;
	double	plane_bis;

	dir_x_bis = params->cam.dir.x;
	plane_bis = params->cam.plane.x;
	params->cam.dir.x = (dir_x_bis * cos(-ANGLE)) -
	(params->cam.dir.y * sin(-ANGLE));
	params->cam.dir.y = (dir_x_bis * sin(-ANGLE)) +
	(params->cam.dir.y * cos(-ANGLE));
	params->cam.plane.x = (plane_bis * cos(-ANGLE)) -
	(params->cam.plane.y * sin(-ANGLE));
	params->cam.plane.y = (plane_bis * sin(-ANGLE)) +
	(params->cam.plane.y * cos(-ANGLE));
	params->event.left_arrow = 0;
	raycasting(params);
}

void	point_right(t_params *params)
{
	double dir_x_bis;
	double plane_bis;

	dir_x_bis = params->cam.dir.x;
	plane_bis = params->cam.plane.x;
	params->cam.dir.x = (dir_x_bis * cos(ANGLE)) -
	(params->cam.dir.y * sin(ANGLE));
	params->cam.dir.y = (dir_x_bis * sin(ANGLE)) +
	(params->cam.dir.y * cos(ANGLE));
	params->cam.plane.x = (plane_bis * cos(ANGLE)) -
	(params->cam.plane.y * sin(ANGLE));
	params->cam.plane.y = (plane_bis * sin(ANGLE)) +
	(params->cam.plane.y * cos(ANGLE));
	params->event.right_arrow = 0;
	raycasting(params);
}
