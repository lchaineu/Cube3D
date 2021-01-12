/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:45:16 by lchaineu          #+#    #+#             */
/*   Updated: 2021/01/12 16:12:37 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		which_spec(t_tab *tab)
{
	if (tab->act_spec == 'c')
		return (convert_c(tab));
	else if (tab->act_spec == 's')
		return (convert_s(tab));
	else if (tab->act_spec == 'p')
		return (convert_p(tab));
	else if (tab->act_spec == 'd')
		return (convert_d_i(tab));
	else if (tab->act_spec == 'i')
		return (convert_d_i(tab));
	else if (tab->act_spec == 'u')
		return (convert_u(tab));
	else if (tab->act_spec == 'x')
		return (convert_x(tab));
	else if (tab->act_spec == 'X')
		return (convert_big_x(tab));
	else
		return (convert_percent(tab));
}

char	*addstrfront(t_tab *tab, char c, int len)
{
	int		i;
	int		j;
	char	*str;

	len = len - ft_strlen(tab->answer);
	if (len < 0)
		len = 0;
	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * (len + 1 + ft_strlen(tab->answer)))))
		return (NULL);
	while (len--)
		str[i++] = c;
	while (tab->answer[j])
		str[i++] = tab->answer[j++];
	str[i] = '\0';
	free(tab->answer);
	return (str);
}

char	*addstrback(t_tab *tab, char c, int len)
{
	int		i;
	int		j;
	char	*str;

	len = len - ft_strlen(tab->answer);
	if (len < 0)
		len = 0;
	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * (len + 1 + ft_strlen(tab->answer)))))
		return (NULL);
	while (tab->answer[j])
		str[i++] = tab->answer[j++];
	while (len--)
		str[i++] = c;
	str[i] = '\0';
	free(tab->answer);
	return (str);
}
