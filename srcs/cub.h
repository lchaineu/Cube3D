#ifndef CUBE3D_H
# define CUBE3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../minilibx_metal/mlx.h"
# include "../Lib19/libft.h"

typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct s_map
{
	char	**map;
}				t_map;


typedef struct s_color
{
	int		red;
	int		green;
	int		blue;

}				t_color;

typedef	struct s_textures
{
	char		*path;
}				t_textures;				


typedef struct s_resolution
{
	int			x_res;
	int			y_res;
}				t_resolution;

typedef struct s_window
{
	void			*ptr;
	t_textures		north;
	t_textures		south;
	t_textures		west;
	t_textures		east;
	t_textures		sprites;
	t_color			floor;
	t_color			ceiling;
	t_resolution	resolution;
}				t_window;

typedef struct s_params
{
	t_window	window;
	char		*mapfile;
	int			save;
	t_map		map;
	t_pos		pos;
}				t_params;

int				set_cub(t_params *params);
void			check_args(int arc, char **argv, t_params *params);
char			*ft_strdup_cub(const char *str);
int				ft_strcmp_cub(char *s1, char *s2);
void			data_parsing(t_params *params);
int				ft_atoi_cub(char *str, int *i, int *rep);
int				is_map_line(char *str);
int				is_empty_line(char *str);
void			malloc_map(t_params *params);
void			get_player_pos(t_pos *pos, t_map map);
void			errors(char *error, t_params *params);



#endif
