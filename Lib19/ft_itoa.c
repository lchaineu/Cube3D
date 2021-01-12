/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:41:55 by lchaineu          #+#    #+#             */
/*   Updated: 2020/10/09 14:41:57 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_in_tab(char *tab, int nbr)
{
	unsigned int nombre;

	if (nbr < 0)
	{
		nombre = -nbr;
		tab[ft_strlen(tab)] = '-';
	}
	else
		nombre = nbr;
	if (nombre / 10 != 0)
		put_in_tab(tab, nombre / 10);
	tab[ft_strlen(tab)] = nombre % 10 + '0';
}

char	*set_to_null(char *tab, int digits)
{
	int i;

	i = 0;
	while (i <= digits)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	int		digits;
	int		nombre;
	char	*tab;

	digits = 1;
	if (n < 0)
		digits++;
	nombre = n;
	nombre++;
	while (nombre / 10 != 0)
	{
		nombre = nombre / 10;
		digits++;
	}
	if (!(tab = (char *)malloc(sizeof(char) * (digits + 1))))
		return (0);
	set_to_null(tab, digits);
	put_in_tab(tab, n);
	tab[ft_strlen(tab)] = '\0';
	return (tab);
}
