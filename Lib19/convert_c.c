/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:45:21 by lchaineu          #+#    #+#             */
/*   Updated: 2021/01/12 16:11:24 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		c_width(t_tab *tab)
{
	if (tab->minus)
	{
		if (!(tab->answer = addstrback(tab, ' ', tab->width)))
			return (-1);
	}
	else
	{
		if (!(tab->answer = addstrfront(tab, ' ', tab->width)))
			return (-1);
	}
	return (1);
}

static	int		display_c(t_tab *tab)
{
	if (tab->width)
		if (c_width(tab) == -1)
			return (-1);
	return (1);
}

int				convert_c(t_tab *tab)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (-1);
	str[0] = va_arg(tab->ap, int);
	str[1] = '\0';
	if (str[0] == '\0')
	{
		tab->is_backslasho = 1;
		if (tab->width >= 1)
			tab->width--;
	}
	if (!(tab->answer = strjoin_back(tab->answer, str)))
		free_malloc_error(str, -1);
	free(str);
	return (display_c(tab));
}
