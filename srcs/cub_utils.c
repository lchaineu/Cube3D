/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:11:51 by lchaineu          #+#    #+#             */
/*   Updated: 2021/03/08 13:57:49 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		is_space(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int		is_char_in_str(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int		check_before_atoi(char *str, int i)
{
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] && str[i] == '-')
		i++;
	if (str[i] && str[i] >= '0' && str[i] <= '9')
		return (0);
	return (1);
}

int		is_map_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' &&
				str[i] != '2' && str[i] != ' ' && str[i] != 'N'
				&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int		is_empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\f' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}
