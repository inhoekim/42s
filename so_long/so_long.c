#include "map/map.h"
#include <stdio.h>

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		ft_printf("[Error] wrong file name\n");
		return (1);
	}
	if (create_map(argv[1]) == FT_ERR)
	{
		ft_printf("[Error] abnormal map file\n");
		return (1);
	}
	mlx_hook(game.window, 2, 0, input, (void *)&game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}