#include "cub.h"

int		set_cub(t_params *params)
{
	params->save = 0;
	if(!(params->mapfile = (char*)malloc(sizeof(char))))
		return (-1);
	params->mapfile[0] = '\0';
	return (1);
}

int		main(int argc, char **argv)
{
	t_params	params;

	check_args(argc, argv, &params);
	data_parsing(&params);
	malloc_map(&params);
	/*params.pointer = mlx_init();
	mlx_new_window(params.pointer, 1000, 1000, "mywindow");
	mlx_loop(params.pointer);*/
}
