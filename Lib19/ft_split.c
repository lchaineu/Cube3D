/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchaineu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:07:31 by lchaineu          #+#    #+#             */
/*   Updated: 2020/10/13 10:07:35 by lchaineu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	nbr_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

unsigned int	nbr_letters(char const *s, char c, unsigned int i)
{
	unsigned int	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

char			*create_word(char const *s, char c, unsigned int *i, char *res)
{
	unsigned int j;

	j = 0;
	while (s[*i] != c && s[*i])
	{
		res[j] = s[*i];
		j++;
		(*i)++;
	}
	res[j] = '\0';
	return (res);
}

char			**free_words(char **res)
{
	int i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char			**res;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (!(res = (char **)malloc(sizeof(char *) * (nbr_words(s, c) + 1))))
		return (NULL);
	while (j < nbr_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		if (!(res[j] = (char *)malloc(sizeof(char)
		* (nbr_letters(s, c, i) + 1))))
			return (free_words(res));
		create_word(s, c, &i, res[j]);
		j++;
	}
	res[j] = 0;
	return (res);
}
