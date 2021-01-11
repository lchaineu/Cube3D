#ifndef CUBE3D_H
# define CUBE3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../minilibx_metal/mlx.h"


typedef struct s_params
{
	void		*pointer;


}				t_params;

int		parsing(t_params params, char *map);

#endif
