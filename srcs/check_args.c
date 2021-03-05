#include "cub.h"

static	void	is_dotcub(char *str, t_params *params)
{
	int len;

	len = (int)ft_strlen(str);
	if (len < 5)
		parsing_errors("Not a valid filename", params);
	if (str[len-4] != '.' || str[len-3] != 'c' || str[len-2] != 'u' || str[len-1] != 'b')
		parsing_errors("Not a valid filename", params);
	if (!(params->mapfile = ft_strdup(str)))
		parsing_errors("Can't malloc filename", params);
}

static	void	is_save(char *str, t_params *params)
{
	if (!(ft_strcmp_cub(str, "--save")))
		parsing_errors("second argument not a save argument\n", params);
	else
	{
		params->save = 1;
	}
}

void		check_args(int argc, char **argv, t_params *params)
{	
	(void)params;
	if (argc == 1)
		parsing_errors("Error: Too few arguments\n", params);
	if (argc == 2)
		is_dotcub(argv[1], params);
	if (argc == 3)
	{
		is_dotcub(argv[1], params);
		is_save(argv[2], params);
	}
	if (argc > 3)
		parsing_errors("Error: Too many arguments\n", params);
}
