/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <lchaineu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:46:23 by lchaineu          #+#    #+#             */
/*   Updated: 2021/01/12 16:18:40 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cut_str(char *str, int len)
{
	char	*new_answer;
	int		i;

	i = 0;
	if (!(new_answer = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str[i] && i < len)
	{
		new_answer[i] = str[i];
		i++;
	}
	new_answer[i] = '\0';
	return (new_answer);
}
