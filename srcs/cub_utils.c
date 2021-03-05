#include "cub.h"

int			is_space(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	return (0);
}

int		is_char_in_str(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int		check_before_atoi(char *str,int i)
{
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] && str[i] == '-')
		i++;
	if (str[i] && str[i] >= '0' && str[i] <= '9')
		return (0);
	return (1);
}

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

void	pix_color(t_params *params, int pix_pos, t_color color)
{
	params->image.info[pix_pos] = color.blue;
	params->image.info[pix_pos + 1] = color.green;
	params->image.info[pix_pos + 2] = color.red;
}

static	void	put_text_color(t_params *params, int pix_pos, t_textures *texture)
{
	int pixel_pos;
	texture->textY += texture->step;
	pixel_pos = texture->textX * texture->img.bpp
	/ 8 + texture->img.size_line * (int)texture->textY;
	params->image.info[pix_pos] =
	texture->img.info[pixel_pos];
	params->image.info[pix_pos + 1] =
	texture->img.info[pixel_pos + 1];
	params->image.info[pix_pos + 2] =
	texture->img.info[pixel_pos + 2];
}

void	draw_wall(t_params *params)
{
	int	i;
	int	pix_pos; 

	i = params->cam.draw_start;
	while (i < params->cam.draw_end)
	{
		pix_pos = params->cam.pix * params->image.bpp
		/ 8 + params->image.size_line * i;
		if (params->cam.compass == 0 && params->cam.dir.raydirX < 0)
			put_text_color(params, pix_pos, &params->window.west);
		else if (params->cam.compass == 0 && params->cam.dir.raydirX > 0)
		{
			put_text_color(params, pix_pos, &params->window.east);
		}
		else if (params->cam.compass == 1 && params->cam.dir.raydirY < 0)
		{
			put_text_color(params, pix_pos, &params->window.north);
		}
		else if (params->cam.compass == 1 && params->cam.dir.raydirY > 0)
		{
			put_text_color(params, pix_pos, &params->window.south);
		}
		i++;
	}	
}
