/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d_i2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:57:01 by lchaineu          #+#    #+#             */
/*   Updated: 2021/01/12 16:11:39 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		convert_d_i(t_tab *tab)
{
	char			*str;
	long int		num;

	num = va_arg(tab->ap, int);
	if (num < 0)
	{
		num = -num;
		tab->negative = 1;
	}
	if (!(str = ft_itoa_p(num, 10, "0123456789")))
		return (-1);
	if (!(tab->answer = strjoin_back(tab->answer, str)))
		free_malloc_error(str, -1);
	free(str);
	if (((tab->negative && !(tab->is_precision)) ||
	(tab->negative && tab->is_precision && (!tab->precision)))
	&& !(tab->width && tab->zero && ft_strlen(tab->answer) < tab->width))
	{
		if (!(tab->answer = strjoin_front(tab->answer, "-")))
			return (-1);
	}
	if (tab->is_precision == 1 && tab->precision == 0 && tab->answer[0] == '0')
		tab->answer[0] = '\0';
	return (display_d(tab));
}
