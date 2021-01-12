/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:46:12 by lchaineu          #+#    #+#             */
/*   Updated: 2021/01/12 16:16:04 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		precision_finder(t_tab *tab, int i, int *maxrange)
{
	while (i < *maxrange)
	{
		if (tab->input[i] == '.')
		{
			tab->is_precision = 1;
			*maxrange = i;
			i++;
			while ((tab->input[i] >= '0' && tab->input[i] <= '9')
			&& (tab->input[i] != tab->act_spec))
			{
				tab->precision = tab->precision * 10;
				tab->precision = tab->precision + (tab->input[i] - '0');
				i++;
			}
		}
		i++;
	}
}

void		width_finder(t_tab *tab, int i, int *maxrange)
{
	int max;

	max = *maxrange;
	while (i < max)
	{
		if (tab->input[i] >= '1' && tab->input[i] <= '9')
		{
			*maxrange = i;
			while ((tab->input[i] >= '0' && tab->input[i] <= '9') && (i < max))
			{
				tab->width = tab->width * 10;
				tab->width = tab->width + (tab->input[i] - '0');
				i++;
			}
		}
		i++;
	}
}

int			char_flag_finder(t_tab *tab, int i, int maxrange, char flag)
{
	while (i < maxrange)
	{
		if (tab->input[i] == flag)
			return (1);
		i++;
	}
	return (0);
}

int			treat(t_tab *tab, int i)
{
	int maxrange;
	int spec_pos;

	if ((spec_pos = find_spec(tab, i)) == -1)
		return (-1);
	maxrange = spec_pos;
	if (maxrange)
	{
		stars_finder(tab, i, maxrange);
		precision_finder(tab, i, &maxrange);
		if (tab->precision < 0)
		{
			tab->is_precision = 0;
			tab->precision = 0;
		}
		width_finder(tab, i, &maxrange);
		if (tab->minus == 0)
			tab->minus = char_flag_finder(tab, i, maxrange, '-');
		tab->zero = char_flag_finder(tab, i, maxrange, '0');
		which_spec(tab);
	}
	return (spec_pos);
}

int			parsing(t_tab *tab)
{
	int i;

	i = 0;
	while (tab->input[i])
	{
		if (tab->input[i] == '%')
		{
			i++;
			if ((i = treat(tab, i)) == -1)
				return (-1);
			ft_pustr(tab->answer, tab);
			free(tab->answer);
			set_again(tab);
		}
		else
		{
			write(1, &tab->input[i], 1);
			tab->len++;
		}
		i++;
	}
	return (1);
}
