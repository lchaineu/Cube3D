# include "cub.h"

int			get_color(t_color *color, char *str)
{
	int i;

	i = 1;
	if (!ft_atoi_cub(str, &i, &color->red))
		ft_printf("Error: Missing color\n");
	if (str[i] == ',')
		i++;
	if (!ft_atoi_cub(str, &i, &color->green))
		ft_printf("Error: Missing color\n");
	if (str[i] == ',')
		i++;
	if (!ft_atoi_cub(str, &i, &color->blue))
		ft_printf("Error: Missing color\n");
	return (i);
}

void			check_color(t_color *color, int i, char *str)
{
	while (str[i])
	{
		if (str[i] != '\f' || str[i] != '\t' || str[i] != '\n' ||
			str[i] != '\r' || str[i] != '\v' || str[i] != ' ' )
			ft_printf("Error: Color line can only contain color values or spaces\n");
		i++;
	}
	if (color->red < 0 || color->red > 255)
		ft_printf("Error: red color non valid\n");
	if (color->green < 0 || color->green > 255)
		ft_printf("Error: green color non valid\n");
	if (color->blue < 0 || color->blue > 255)
		ft_printf("Error: blue color non valid\n");
}

static void		get_textures(t_textures *textures, char *str)
{
	int i;

	if (str[0] == 'S' && str[1] != 'O')
		i = 1;
	else
		i = 2;
	while (str[i] == ' ')
		i++;
	textures->path = ft_strdup(str + i);
}

static void		check_textures(t_textures *textures)
{
	int i;
	int len;

	i = 0;
	len = (int)ft_strlen(textures->path);
	while(textures->path[i])
	{	
		if (textures->path[i] == '\f' || textures->path[i] == '\t' ||
				textures->path[i] == '\n' ||
				textures->path[i] == '\r' || textures->path[i] == '\v' || textures->path[i] == ' ')
			ft_printf("Error: not a good path for texture\n");
		i++;
	}
	if (textures->path[len-4] != '.' || textures->path[len-3] != 'x'
			|| textures->path[len-2] != 'p' || textures->path[len-1] != 'm')
	ft_printf("Error: not a good path for texture\n");
}

static void		get_resolution(t_params *params, char *str)
{
	int i;

	i = 1;
	ft_atoi_cub(str, &i , &params->window.resolution.x_res);
	ft_atoi_cub(str, &i , &params->window.resolution.y_res);
}

static void		get_north_texture(t_params *params, char *data)
{
	get_textures(&params->window.north, data);
	check_textures(&params->window.north);
}

static void		get_south_texture(t_params *params, char *data)
{
	get_textures(&params->window.south, data);
	check_textures(&params->window.south);
}

static void		get_west_texture(t_params *params, char *data)
{
	get_textures(&params->window.west, data);
	check_textures(&params->window.west);
}

static void		get_east_texture(t_params *params, char *data)
{
	get_textures(&params->window.east, data);
	check_textures(&params->window.east);
}

static void		get_sprite_texture(t_params *params, char *data)
{
	get_textures(&params->sprite.texture, data);
	check_textures(&params->sprite.texture);
}

static void		get_floor_color(t_params *params, char *data)
{
	int i;

	i = 1;
	while(data[i] && !(data[i] >= '0' && data[i] <= '9'))
	{
		if (data[i] != ' ')
			ft_printf("Error: Color line can only contain color values or spaces\n");
		i++;
	}
	i = get_color(&params->window.floor, data);
	check_color(&params->window.floor, i, data);
}

static void		get_ceiling_color(t_params *params, char *data)
{
	int i;

	i = 1;
	while(data[i] && !(data[i] >= '0' && data[i] <= '9'))
	{
		if (data[i] != ' ')
			ft_printf("Error: Color line can only contain color values or spaces\n");
		i++;
	}
	i = get_color(&params->window.ceiling, data);
	check_color(&params->window.ceiling, i, data);
}

static	void	get_data(t_params *params, char *data)
{
	if (data[0] == 'R')
		get_resolution(params, data);
	else if (data[0] == 'N' && data[1] == 'O')
		get_north_texture(params, data);
	else if (data[0] == 'S' && data[1] == 'O')
		get_south_texture(params, data);
	else if (data[0] == 'W' && data[1] == 'E')
		get_west_texture(params, data);
	else if (data[0] == 'E' && data[1] == 'A')
		get_east_texture(params, data);
	else if (data[0] == 'S' && data[1] != 'O')
		get_sprite_texture(params, data);
	else if (data[0] == 'F')
		get_floor_color(params, data);
	else if (data[0] == 'C')
		get_ceiling_color(params, data);
}

void				data_parsing(t_params *params)
{
	char	*data;
	int		fd;

	if ((fd = open(params->mapfile, O_RDONLY)) == (-1))
		ft_printf("Error: Can't read file\n");
	while (get_next_line(fd, &data))
	{
		if (is_map_line(data))
			free(data);
		else
		{
			get_data(params, data);
			free(data);
		}
	}
	close(fd);
}
