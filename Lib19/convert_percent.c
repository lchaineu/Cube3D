/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:45:36 by lchaineu          #+#    #+#             */
/*   Updated: 2021/01/12 16:11:51 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		percent_width(t_tab *tab)
{
	if (tab->minus)
	{
		if (!(tab->answer = addstrback(tab, ' ', tab->width)))
			return (-1);
	}
	else
	{
		if (tab->zero)
		{
			if (!(tab->answer = addstrfront(tab, '0', tab->width)))
				return (-1);
			if (tab->negative && tab->answer[0] != '-')
				tab->answer[0] = '-';
		}
		else
		{
			if (!(tab->answer = addstrfront(tab, ' ', tab->width)))
				return (-1);
		}
	}
	return (1);
}

static	int		display_percent(t_tab *tab)
{
	if (tab->width)
		if (percent_width(tab) == -1)
			return (-1);
	return (1);
}

int				convert_percent(t_tab *tab)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (-1);
	str[0] = '%';
	str[1] = '\0';
	if (!(tab->answer = strjoin_back(tab->answer, str)))
		free_malloc_error(str, -1);
	free(str);
	return (display_percent(tab));
}
