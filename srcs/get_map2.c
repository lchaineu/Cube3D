#include "cub.h"

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