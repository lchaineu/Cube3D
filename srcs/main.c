#include "cube3d.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	void *ptr;

	ptr = mlx_init();
	mlx_new_window(ptr, 1000, 1000, "mywindow");
	mlx_loop(ptr);
}