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
	set_parsing_val(&params);
	data_parsing(&params);
	malloc_map(&params);
	if (!(params.ptr = mlx_init()))
		errors("fail to init mlx", &params);
	create_cub(&params);
	if (argc == 3)
		save(&params);
	event(&params);
}
