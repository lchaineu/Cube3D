/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:06:26 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/05 16:07:13 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		associate_event(t_params *params)
{
	if (params->event.w)
		move_forward(params);
	if (params->event.s)
		move_backward(params);
	if (params->event.d)
		move_right(params);
	if (params->event.a)
		move_left(params);
	if (params->event.right_arrow)
		point_right(params);
	if (params->event.left_arrow)
		point_left(params);
	return (1);
}

int		press(int pressed_key, t_params *params)
{
	if (pressed_key == 13)
		params->event.w = 1;
	if (pressed_key == 1)
		params->event.s = 1;
	if (pressed_key == 2)
		params->event.d = 1;
	if (pressed_key == 0)
		params->event.a = 1;
	if (pressed_key == 124)
		params->event.right_arrow = 1;
	if (pressed_key == 123)
		params->event.left_arrow = 1;
	return (1);
}

int		release(int pressed_key, t_params *params)
{
	if (pressed_key == 53 || pressed_key == 17)
		do_exit(params);
	return (1);
}

int		red_cross(t_params *params)
{
	do_exit(params);
	return (1);
}

void	event(t_params *params)
{
	mlx_hook(params->window.ptr, 2, 0, press, params);
	mlx_hook(params->window.ptr, 3, 0, release, params);
	mlx_hook(params->window.ptr, 17, 0, red_cross, params);
	mlx_loop_hook(params->ptr, associate_event, params);
	mlx_loop(params->ptr);
}
