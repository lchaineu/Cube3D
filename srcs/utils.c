#include "cub.h"

char	*ft_strdup(const char *str)
{
	char	*newstr;
	int		i;
	int		len;

	i = 0;
	if (!(str) || str == 0)
		return (ft_strdup("(null)"));
	else
		len = ft_strlen(str);
	if (!(newstr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[len] = '\0';
	return (newstr);
}

int		ft_strcmp(char *s1, char *s2)
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