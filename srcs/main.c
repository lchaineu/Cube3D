#include "cube3d.h"

int main(int argc, char **argv)
{
	t_params	params;
	(void) argv;

	if (argc != 2)
	{	
		return (-1);
		printf("ERROR:\nNot enough arguments.\n");
	}
	else
	{
		parsing(params, argv[1]);
	}
	
	params.pointer = mlx_init();
	mlx_new_window(params.pointer, 1000, 1000, "mywindow");
	mlx_loop(params.pointer);
}