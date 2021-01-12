#ifndef CUBE3D_H
# define CUBE3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../minilibx_metal/mlx.h"
# include "../Lib19/libft.h"

typedef struct s_params
{
	void		*pointer;
	char		*mapfile;


}				t_params;

void			check_args(int arc, char **argv, t_params *params);
char			*ft_strdup(const char *str);
int				ft_strcmp(char *s1, char *s2);
int				map_parsing(t_params *params);

#endif
