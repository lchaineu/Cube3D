/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:14:44 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/10 13:21:06 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int		get_color(t_params *params, t_color *color, char *str)
{
	int i;

	i = 1;
	if (check_before_atoi(str, i))
		parsing_errors("color line not conform", params);
	ft_atoi_cub(str, &i, &color->red);
	if (str[i] == ',')
		i++;
	if (check_before_atoi(str, i))
		parsing_errors("color line not conform", params);
	ft_atoi_cub(str, &i, &color->green);
	if (str[i] == ',')
		i++;
	if (check_before_atoi(str, i))
		parsing_errors("color line not conform", params);
	ft_atoi_cub(str, &i, &color->blue);
	return (i);
}

static void		get_texture(t_textures *textures, char *str)
{
	int i;

	if (str[0] == 'S' && str[1] != 'O')
		i = 1;
	else
		i = 2;
	while (str[i] == ' ')
		i++;
	textures->path = ft_strdup(str + i);
}

static void		get_resolution(t_params *params, char *str)
{
	int i;

	i = 1;
	params->window.res = 1;
	while (str[i] && (!(str[i] >= '0' && str[i] <= '9')) && str[i] != '-')
	{
		if (!(is_space(str[i++])))
			parsing_errors("Resolution must only contain height and width",
			params);
	}
	if (check_before_atoi(str, i))
		parsing_errors("Height and width are needed to build a window", params);
	ft_atoi_cub(str, &i, &params->window.resolution.x_res);
	if (check_before_atoi(str, i))
		parsing_errors("Height and width are needed to build a window", params);
	ft_atoi_cub(str, &i, &params->window.resolution.y_res);
	while (str[i])
		if (!(is_space(str[i++])))
			parsing_errors("Can't give other values than heigth and width",
			params);
	if (!(params->cam.dist_buffer = malloc(sizeof(double) *
	params->window.resolution.x_res)))
		parsing_errors("Can't malloc distance buffer", params);
	check_resolution(params);
}

static void		get_textures(t_params *params, char *data)
{
	if (data[0] == 'N' && data[1] == 'O')
	{
		get_texture(&params->window.north, data);
		check_textures(&params->window.north, params);
	}
	else if (data[0] == 'S' && data[1] == 'O')
	{
		get_texture(&params->window.south, data);
		check_textures(&params->window.south, params);
	}
	else if (data[0] == 'W' && data[1] == 'E')
	{
		get_texture(&params->window.west, data);
		check_textures(&params->window.west, params);
	}
	else if (data[0] == 'E' && data[1] == 'A')
	{
		get_texture(&params->window.east, data);
		check_textures(&params->window.east, params);
	}
	else if (data[0] == 'S' && data[1] != 'O')
	{
		get_texture(&params->sprite.textures, data);
		check_textures(&params->sprite.textures, params);
	}
}

void			get_data(t_params *params, char *data)
{
	if (data[0] == 'R')
		get_resolution(params, data);
	else if (data[0] == 'F')
	{
		get_color(params, &params->window.floor, data);
		check_color(params, &params->window.floor);
	}
	else if (data[0] == 'C')
	{
		get_color(params, &params->window.ceiling, data);
		check_color(params, &params->window.ceiling);
	}
	get_textures(params, data);
}
