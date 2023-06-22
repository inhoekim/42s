/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 01:38:29 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/21 01:38:30 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map.h"
#include "core/core.h"
#include <stdio.h>
#include <stdlib.h>

int	game_exit()
{
	//free_all();
	exit(0);
}

static void	game_start(t_game *game)
{
	if (init_game(game) == FT_ERR)
	{
		perror("[Error] allocation failed");
		exit (1);
	}
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_X, WIN_Y, "so_long");
	mlx_hook(game->win, 2, 0, &key_input, &game);
	mlx_hook(game->win, 17, 0, &game_exit, &game);
	mlx_loop_hook(game->mlx, &frame_update, &game);
	mlx_loop(game->mlx);
}

int	main(int argc, char** argv)
{
	t_game	game;

	if (argc != 2)
	{
		perror("[Error] wrong file name");
		exit (1);
	}
	if (create_map(argv[1]) == FT_ERR)
	{
		perror("[Error] abnormal map file");
		exit (1);
	}
	game_start(&game);
	clear_map(get_map()->info.size.y - 1);
	return (0);
}
