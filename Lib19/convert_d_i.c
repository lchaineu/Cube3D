/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:55:20 by lchaineu          #+#    #+#             */
/*   Updated: 2021/01/12 16:11:32 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		d_precision(t_tab *tab)
{
	if (!(tab->answer = addstrfront(tab, '0', tab->precision)))
		return (-1);
	if (tab->negative && tab->answer[0] != '-')
		if (!(tab->answer = strjoin_front(tab->answer, "-")))
			return (-1);
	return (1);
}

int		d_width_no_minus(t_tab *tab)
{
	if (tab->zero && !(tab->precision) && !(tab->is_precision))
	{
		if (!(tab->answer = addstrfront(tab, '0', tab->width)))
			return (-1);
		if (tab->negative && tab->answer[0] != '-')
			tab->answer[0] = '-';
	}
	else
	{
		if (tab->is_precision && tab->precision == 0 && tab->negative)
			if (add_minus(tab) == -1)
				return (-1);
		if (!(tab->answer = addstrfront(tab, ' ', tab->width)))
			return (-1);
	}
	return (1);
}

int		d_width(t_tab *tab)
{
	if (tab->minus)
	{
		if (tab->negative && !(search_string('-', tab->answer)))
			tab->width--;
		if (!(tab->answer = addstrback(tab, ' ', tab->width)))
			return (-1);
	}
	else
	{
		if ((d_width_no_minus(tab)) == -1)
			return (-1);
	}
	if (add_minus(tab) == -1)
		return (-1);
	return (1);
}

int		display_d(t_tab *tab)
{
	if (tab->precision)
		if (d_precision(tab) == -1)
			return (-1);
	if (tab->width)
		if (d_width(tab) == -1)
			return (-1);
	return (1);
}

int		add_minus(t_tab *tab)
{
	if (tab->negative && !(search_string('-', tab->answer)))
		if (!(tab->answer = strjoin_front(tab->answer, "-")))
			return (-1);
	return (1);
}
