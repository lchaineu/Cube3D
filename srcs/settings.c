#include "cub.h"

void	set_cub_val(t_params *params)
{	
	params->image.ptr = NULL;
	params->window.north.img.ptr = NULL;
	params->window.south.img.ptr = NULL;
	params->window.east.img.ptr = NULL;
	params->window.west.img.ptr = NULL;
	params->sprite.texture.img.ptr = NULL;
}

void	get_textures(t_params *params
{
	if (!(params->window.north.img.ptr = mlx_xpm_file_to_image()))


}

void	create_cub(t_params *params)
{
	set_cub_val(params);
	if (!(params->window.ptr = mlx_new_window(params->ptr,
			params->window.resolution.x_res, params->window.resolution.y_res, "Cub3D")))
		errors("Can't create window", params);
	if (!(params->image.ptr = mlx_new_image(params->ptr, params->window.resolution.x_res,
			params->window.resolution.y_res)))
		errors("Can't create image", params);
	if (!(params->image.info = (unsigned char *)mlx_get_data_addr(params->image.ptr, &params->image.bpp, &params->image.size_line, &params->image.endian)))
		errors("Can't get image data", params);
	mlx_loop(params->ptr);
}

void	set_parsing_val(t_params *params)
{
	params->window.north.path = NULL;
	params->window.south.path = NULL;
	params->window.east.path = NULL;
	params->window.west.path = NULL;
	params->.sprites.texture.path = NULL;
	params->map.map = NULL;
	params->window.floor.blue = 0;
	params->window.floor.green = 0;
	params->window.floor.red = 0;
	params->window.ceiling.blue = 0;
	params->window.ceiling.green = 0;
	params->window.ceiling.red = 0;
	params->window.resolution.x_res = 0;
	params->window.resolution.y_res = 0;
}