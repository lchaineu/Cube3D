# include "cub.h"

/*int		is_map_data(char *mapfile_data)
{
	int i;

	i = 0;
	if (mapfile_data[0] == '\0')
		return (0);
	while (mapfile_data[i])
	{
		if (!(isinstr("012 NESW", mapfile_data[i])))
			return (0);
		i++;
	}
	return (1);
}

int		file_parsing(t_params *params, char *mapfile_data, int fd)
{
	if (is_map_data(mapfile_data))



}

int		map_parsing(t_params *params)
{
	char	*mapfile_data;
	int		fd;

	if ((fd = open(params->mapfile, O_RDONLY)) == (-1))
		printf("Error: Can't read file");
	while (get_next_line(fd, &mapfile_data))
	{
		file_parsing(params, mapfile_data, fd);
	}
	
	return (0);

}*/