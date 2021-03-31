/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:54:18 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/27 11:48:50 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static	void	is_dotcub(char *str, t_params *params)
{
	int len;

	len = (int)ft_strlen(str);
	if (len < 5)
	{
		ft_printf("Error:\nNot a valid filename");
		exit(EXIT_FAILURE);
	}
	if (str[len - 4] != '.' || str[len - 3] != 'c'
	|| str[len - 2] != 'u' || str[len - 1] != 'b')
	{
		ft_printf("Error:\nNot a valid filename");
		exit(EXIT_FAILURE);
	}
	if (!(params->mapfile = ft_strdup(str)))
		parsing_errors("Can't malloc filename", params);
}

static	void	is_save(char *str, t_params *params)
{
	if (!(ft_strcmp_cub(str, "--save")))
	{
		ft_printf("Error:\nSecond argument should be --save");
		exit(EXIT_FAILURE);
	}
	else
	{
		params->save = 1;
	}
}

void			check_args(int argc, char **argv, t_params *params)
{
	(void)params;
	if (argc == 1)
	{
		ft_printf("Error: Too few arguments");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
		is_dotcub(argv[1], params);
	if (argc == 3)
	{
		is_dotcub(argv[1], params);
		is_save(argv[2], params);
	}
	if (argc > 3)
	{
		ft_printf("Error: Too many arguments");
		exit(EXIT_FAILURE);
	}
}
