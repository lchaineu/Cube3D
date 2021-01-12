/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:45:32 by lchaineu          #+#    #+#             */
/*   Updated: 2021/01/12 16:11:44 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		p_precision(t_tab *tab)
{
	if (!(tab->answer = addstrfront(tab, '0', tab->precision)))
		return (-1);
	if (tab->negative)
		if (!(tab->answer = strjoin_front(tab->answer, "-")))
			return (-1);
	return (1);
}

static	int		p_width(t_tab *tab)
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

static	int		display_p(t_tab *tab)
{
	if (tab->precision)
		if (p_precision(tab) == -1)
			return (-1);
	if (tab->width)
		if (p_width(tab) == -1)
			return (-1);
	return (1);
}

int				convert_p(t_tab *tab)
{
	char					*str;
	unsigned long long int	ptr;

	ptr = va_arg(tab->ap, unsigned long long int);
	if (!(tab->is_precision && !ptr))
	{
		if (!(str = ft_itoa_p(ptr, 16, "0123456789abcdef")))
			return (-1);
		if (!(tab->answer = strjoin_back(tab->answer, str)))
			free_malloc_error(str, -1);
		free(str);
	}
	if (!(tab->answer = strjoin_front(tab->answer, "0x")))
		return (-1);
	return (display_p(tab));
}
