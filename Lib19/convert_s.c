/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:45:40 by lchaineu          #+#    #+#             */
/*   Updated: 2021/01/12 16:13:52 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		s_precision(t_tab *tab)
{
	if (tab->precision > ft_strlen(tab->answer))
		tab->precision = 0;
	if (!(tab->answer = addstrfront(tab, ' ', tab->precision)))
		return (-1);
	return (1);
}

static	int		s_width(t_tab *tab)
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

static	int		display_s(t_tab *tab)
{
	if (tab->precision)
		if (s_precision(tab) == -1)
			return (-1);
	if (tab->width)
		if (s_width(tab) == -1)
			return (-1);
	return (1);
}

int				convert_s(t_tab *tab)
{
	char	*str;

	if (!(str = ft_strdup_printf(va_arg(tab->ap, char *))))
		return (-1);
	if (tab->precision < ft_strlen(str) && tab->is_precision)
	{
		free(tab->answer);
		if (!(tab->answer = cut_str(str, tab->precision)))
			return (-1);
	}
	else
	{
		if (!(tab->answer = strjoin_back(tab->answer, str)))
			free_malloc_error(str, -1);
	}
	free(str);
	return (display_s(tab));
}
