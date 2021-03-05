# include "cub.h"

int			get_color(t_params *params, char *str)
{
	int i;

	i = 1;
	if (!ft_atoi_cub(str, &i, &params->color.red))
		parsing_errors("Error: Missing color\n", params);
	if (str[i] == ',')
		i++;
	if (!ft_atoi_cub(str, &i, &params->color.green))
		parsing_errors("Error: Missing color\n", params);
	if (str[i] == ',')
		i++;
	if (!ft_atoi_cub(str, &i, &params->color.blue))
		parsing_errors("Error: Missing color\n", params);
	return (i);
}

void			check_color(t_params *params, int i, char *str)
{
	while (str[i])
	{
		if (str[i] != '\f' || str[i] != '\t' || str[i] != '\n' ||
			str[i] != '\r' || str[i] != '\v' || str[i] != ' ' )
			parsing_errors("Error: Color line can only contain color values or spaces\n", params);
		i++;
	}
	if (params->color.red < 0 || params->color.red > 255)
		parsing_errors("Error: red color non valid\n", params);
	if (params->color.green < 0 || params->color.green > 255)
		parsing_errors("Error: green color non valid\n", params);
	if (params->color.blue < 0 || params->color.blue > 255)
		parsing_errors("Error: blue color non valid\n", params);
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

static void		check_textures(t_textures *textures, t_params *params)
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
			parsing_errors("Error: not a good path for texture\n", params);
		i++;
	}
	if (textures->path[len-4] != '.' || textures->path[len-3] != 'x'
			|| textures->path[len-2] != 'p' || textures->path[len-1] != 'm')
	parsing_errors("Error: not a good path for texture\n", params);
}

static void		get_resolution(t_params *params, char *str)
{
	int i;

	i = 1;
	params->window.res = 1;
	while (str[i] && (!(str[i] >= '0' && str[i] <= '9')) && str[i] != '-')
	{
		if (!(is_space(str[i++])))
			parsing_errors("Resolution must only contain height and width\n", params);
	}
	if (check_before_atoi(str,i))
		parsing_errors("Height and width are needed to build a window\n", params);
	ft_atoi_cub(str, &i , &params->window.resolution.x_res);
	if (check_before_atoi(str,i))
		parsing_errors("Height and width are needed to build a window\n", params);
	ft_atoi_cub(str, &i , &params->window.resolution.y_res);
	while (str[i])
		if (!(is_space(str[i++])))
			parsing_errors("Can't give other values than heigth and width on this line\n", params);
	if (!(params->cam.dist_buffer = malloc(sizeof(double) * 
	params->window.resolution.x_res)))
		parsing_errors("Can't malloc distance buffer\n", params);
}

static void		get_north_texture(t_params *params, char *data)
{
	get_textures(&params->window.north, data);
	check_textures(&params->window.north, params);
}

static void		get_south_texture(t_params *params, char *data)
{
	get_textures(&params->window.south, data);
	check_textures(&params->window.south, params);
}

static void		get_west_texture(t_params *params, char *data)
{
	get_textures(&params->window.west, data);
	check_textures(&params->window.west, params);
}

static void		get_east_texture(t_params *params, char *data)
{
	get_textures(&params->window.east, data);
	check_textures(&params->window.east, params);
}

static void		get_sprite_texture(t_params *params, char *data)
{
	get_textures(&params->sprite.textures, data);
	check_textures(&params->sprite.textures, params);
}

static void		get_floor_color(t_params *params, char *data)
{
	int i;

	i = 1;
	while(data[i] && !(data[i] >= '0' && data[i] <= '9'))
	{
		if (data[i] != ' ')
			parsing_errors("Error: Color line can only contain color values or spaces\n", params);
		i++;
	}
	i = get_color(params, data);
	check_color(params, i, data);
}

static void		get_ceiling_color(t_params *params, char *data)
{
	int i;

	i = 1;
	while(data[i] && !(data[i] >= '0' && data[i] <= '9'))
	{
		if (data[i] != ' ')
			parsing_errors("Error: Color line can only contain color values or spaces\n", params);
		i++;
	}
	i = get_color(params, data);
	check_color(params, i, data);
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
		parsing_errors("Error: Can't read file\n", params);
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
