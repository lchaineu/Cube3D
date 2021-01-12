#include "cub.h"

static	void	is_dotcub(char *str, t_params *params)
{
	int len;

	len = (int)ft_strlen(str);
	if (len < 5)
		ft_printf("File name incorrect\n");
	if (str[len-4] != '.' || str[len-3] != 'c' || str[len-2] != 'u' || str[len-1] != 'b')
		ft_printf("File name incorrect\n");
	if (!(params->mapfile = ft_strdup(str)))
		ft_printf("Error:malloc filename\n");
}

static	void	is_save(char *str, t_params *params)
{
	(void)params;
	if (!(ft_strcmp("--save", str)))
		printf("second argument not a save argument\n");
}


void		check_args(int argc, char **argv, t_params *params)
{	
	(void)params;
	if (argc == 1)
		printf("Error: Too few arguments");
	if (argc == 2)
		is_dotcub(argv[1], params);
	if (argc == 3)
	{
		is_dotcub(argv[1], params);
		is_save(argv[2], params);
	}
	if (argc > 3)
		printf("Error: Too many arguments");
}