/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:07:17 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/05 16:07:27 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*int		set_cub(t_params *params)
{
	if(!(params->mapfile = (char*)malloc(sizeof(char))))
		return (-1);
	params->mapfile[0] = '\0';
	return (1);
}*/

int		main(int argc, char **argv)
{
	t_params	params;

	check_args(argc, argv, &params);
	if (!(params.ptr = mlx_init()))
		parsing_errors("fail to init mlx", &params);
	set_parsing_val(&params);
	data_parsing(&params);
	malloc_map(&params);
	create_cub(&params);
	if (argc == 3)
		make_bmp(&params);
	event(&params);
}
