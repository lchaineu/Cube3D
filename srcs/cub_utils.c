#include "cub.h"

int		ft_strcmp_cub(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i++])
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}

int		ft_atoi_cub(char *str, int *i, int *rep)
{
	int sign;
	int color;

	sign = 0;
	color = 0;
	*rep = 0;
	while (str[*i] == '\f' || str[*i] == '\t' || str[*i] == '\n' ||
			str[*i] == '\r' || str[*i] == '\v' || str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = 1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*rep = *rep * 10 + str[*i] - '0';
		(*i)++;
		color = 1;
	}
	if (sign == 1)
		*rep = -(*rep);
	if (color == 0)
		return (0);
	return (1);		
}

int		is_map_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' &&
				str[i] != '2' && str[i] != ' ' && str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int		is_empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\f' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}
