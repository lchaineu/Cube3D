#include "cub.h"

int main(int argc, char **argv)
{
	t_params	params;

	check_args(argc, argv, &params);
	map_parsing(&params);
	/*params.pointer = mlx_init();
	mlx_new_window(params.pointer, 1000, 1000, "mywindow");
	mlx_loop(params.pointer);*/
}