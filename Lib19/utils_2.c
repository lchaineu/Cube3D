/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:46:18 by lchaineu          #+#    #+#             */
/*   Updated: 2021/01/12 16:18:34 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_pustr(char *str, t_tab *tab)
{
	int i;

	i = 0;
	if (str)
	{
		if (tab->is_backslasho == 1 && tab->minus)
			write(1, "\0", 1);
		while (str[i])
			write(1, &str[i++], 1);
		if (tab->is_backslasho == 1 && !(tab->minus))
			write(1, "\0", 1);
	}
	if (tab->is_backslasho)
		tab->len++;
	tab->len = tab->len + ft_strlen(tab->answer);
}

char			*strjoin_back(char *s1, char *s2)
{
	char	*new_answer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new_answer = (char *)malloc(sizeof(char)
	* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		new_answer[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_answer[i] = s2[j];
		j++;
		i++;
	}
	new_answer[i] = '\0';
	free(s1);
	return (new_answer);
}

char			*strjoin_front(char *s1, char *s2)
{
	char	*new_answer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new_answer = (char *)malloc(sizeof(char)
		* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s2[i])
	{
		new_answer[i] = s2[i];
		i++;
	}
	while (s1[j])
	{
		new_answer[i] = s1[j];
		i++;
		j++;
	}
	new_answer[i] = '\0';
	free(s1);
	return (new_answer);
}

static	int		getdigits(unsigned long long int nombre, int base)
{
	int i;

	i = 1;
	while (nombre / base > 0)
	{
		nombre = nombre / base;
		i++;
	}
	return (i);
}

char			*ft_itoa_p(unsigned long long int nombre,
							int base, char *charbase)
{
	int		digits;
	char	*str;

	digits = getdigits(nombre, base);
	if (!(str = malloc(sizeof(char) * (digits + 1))))
		return (NULL);
	str[digits] = '\0';
	while (digits)
	{
		str[digits - 1] = charbase[nombre % base];
		nombre = nombre / base;
		digits--;
	}
	return (str);
}
