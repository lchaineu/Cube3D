#include "cub.h"

int		is_map_closed(int y, int x, char **map)
{
	
	if (x == 0 || y == 0)
		return (0);
	if (map[y + 1] == NULL)
		return (0);
	if (map[y][(ft_strlen(map[y]) - 1)] != '1')
		return (0);
	if ((ft_strlen(map[y - 1]) - 1) < x)
		return (0);
	if ((ft_strlen(map[y + 1]) - 1) < x)
		return (0);
	if (!(is_char_in_str("012NSEW", map[y - 1][x])))
		return (0);
	if (!(is_char_in_str("012NSEW", map[y + 1][x])))
		return (0);
	if (!(is_char_in_str("012NSEW", map[y][x - 1])))
		return (0);
	if (!(is_char_in_str("012NSEW", map[y][x + 1])))
		return (0);
	return (1);
}

int		is_a_good_map(char **map)
{
	int x;
	int y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x])
		{
			if (is_char_in_str("02NSEW", map[y][x]))
				if (!(is_map_closed(y, x, map)))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	get_pos_bis(t_params *params, char c)
{
	if (c == 'E')
	{
		params->cam.dir.x = 1;
		params->cam.dir.y = 0;
		params->cam.plane.x = 0;
		params->cam.plane.y = 0.66;
	}
	if (c == 'W')
	{
		params->cam.dir.x = -1;
		params->cam.dir.y = 0;
		params->cam.plane.x = 0;
		params->cam.plane.y = -0.66;
	}
}

void	get_pos(t_params *params, int x, int y, char c)
{
	params->pos.x = (double)x + 0.5;
	params->pos.y = (double)y + 0.5;
	if (c == 'N')
	{
		params->cam.dir.x = 0;
		params->cam.dir.y = -1;
		params->cam.plane.x = 0.66;
		params->cam.plane.y = 0;
	}
	if (c == 'S')
	{
		params->cam.dir.x = 0;
		params->cam.dir.y = 1;
		params->cam.plane.x = -0.66;
		params->cam.plane.y = 0;
	}
	get_pos_bis(params, c);
}