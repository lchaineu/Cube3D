#ifndef CUBE3D_H
# define CUBE3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../minilibx_metal/mlx.h"
# include "../Lib19/libft.h"

typedef struct s_vect
{
	double x;
	double y;
}				t_vect;

typedef struct s_dir
{
	double		x;
	double		y;
	double		raydirX;
	double		raydirY;
}			t_dir;

typedef struct s_cam
{
	int		pix;
	double	cam_x;
	int		hit;
	t_dir	dir;
	t_vect	plane;
	t_vect	deltadist;
	t_vect	sidedist;
	t_vect	step;
	int		compass;
	double	walldist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wallX;
}				t_cam;

typedef struct s_image
{
	void			*ptr;
	unsigned char	*info;
	int				bpp;
	int				size_line;
	int				endian;
}				t_image;

typedef struct s_sprites
{
	t_texture		texture;

}				t_sprites;
typedef struct s_map
{
	char	**map;
	t_vect	map_pos;
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
	int			textX;
	int			width;
	int			height;
	double		step;
	int			textY;
	t_image		img;
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
	t_color			floor;
	t_color			ceiling;
	t_resolution	resolution;
}				t_window;

typedef struct s_params
{
	void		*ptr;
	t_window	window;
	char		*mapfile;
	int			save;
	t_map		map;
	t_vect		pos;
	t_image		image;
	t_cam		cam;
	t_sprites	sprite;
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
void			search_pos(t_map map, t_params *params);
void			errors(char *error, t_params *params);
void			set_parsing_val(t_params *params);
void			create_cub(t_params *params);
void			get_pos(t_params *params, int x, int y, char c);
void			draw_mesures(t_params *params);
void			get_wall_x(t_params *params);
void			draw_buffer(t_params *params);






#endif
