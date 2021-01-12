/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:46:15 by lchaineu          #+#    #+#             */
/*   Updated: 2021/01/12 16:16:32 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	stars_finder(t_tab *tab, int i, int maxrange)
{
	while (i < maxrange)
	{
		if (tab->input[i] == '*' && (tab->input[i - 1] != '.'))
		{
			tab->width = va_arg(tab->ap, int);
			if (tab->width < 0)
			{
				tab->minus = 1;
				tab->width = -(tab->width);
			}
		}
		if (tab->input[i] == '*' && (tab->input[i - 1] == '.'))
		{
			tab->is_precision = 1;
			tab->precision = va_arg(tab->ap, int);
		}
		i++;
	}
}

int		find_spec(t_tab *tab, int i)
{
	while (tab->input[i])
	{
		if (search_string(tab->input[i], "cspdiuxX%"))
		{
			tab->act_spec = tab->input[i];
			return (i);
		}
		i++;
	}
	return (-1);
}
