/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:44:19 by lchaineu          #+#    #+#             */
/*   Updated: 2020/10/09 14:44:21 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	position;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (needle[j] == haystack[i])
		{
			position = i;
			while (needle[j] == haystack[i] && i < len)
			{
				i++;
				j++;
				if (needle[j] == '\0')
					return (&((char*)haystack)[position]);
			}
		}
		else
			i++;
	}
	return (NULL);
}
