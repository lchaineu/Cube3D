#include "cub.h"

static	void	is_dotcub(char *str, t_params *params)
{
	int len;

	len = (int)ft_strlen(str);
	if (len < 5)
		errors("Not a valid filename", params);
	if (str[len-4] != '.' || str[len-3] != 'c' || str[len-2] != 'u' || str[len-1] != 'b')
		errors("Not a valid filename", params);
	if (!(params->mapfile = ft_strdup(str)))
		errors("Can't malloc filename", params);
}

static	void	is_save(char *str, t_params *params)
{
	(void)params;
	if (!(ft_strcmp("--save", str)))
		ft_printf("second argument not a save argument\n");
	else
	{
		params->save = 1;
	}
}

void		check_args(int argc, char **argv, t_params *params)
{	
	(void)params;
	if (argc == 1)
		ft_printf("Error: Too few arguments\n");
	if (argc == 2)
		is_dotcub(argv[1], params);
	if (argc == 3)
	{
		is_dotcub(argv[1], params);
		is_save(argv[2], params);
	}
	if (argc > 3)
		ft_printf("Error: Too many arguments\n");
}
