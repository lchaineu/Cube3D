/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_modified.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:51:03 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/08 14:00:27 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_strcmp_cub(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i++])
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}

int		ft_atoi_cub(char *str, int *i, int *rep)
{
	int sign;
	int color;

	sign = 0;
	color = 0;
	*rep = 0;
	while (is_space(str[*i]))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = 1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*rep = *rep * 10 + str[*i] - '0';
		(*i)++;
		color = 1;
	}
	if (sign == 1)
		*rep = -(*rep);
	if (color == 0)
		return (0);
	return (1);
}
