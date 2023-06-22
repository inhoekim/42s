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
#include "lib_printf/includes/ft_printf_bonus.h"
#include <stdio.h>
#include <stdlib.h>

int	game_exit()
{
	//free_all();
	exit(0);
}

int	main(int argc, char** argv)
{
	t_game	game;

	if (argc != 2)
	{
		perror("[Error] wrong file name");
		// ft_printf("[Error] wrong file name\n");
		return (1);
	}
	if (create_map(argv[1]) == FT_ERR)
	{
		perror("[Error] abnormal map file");
		return (1);
	}
	init_game(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1000, 600, "so_long");

	alloc_img(&game);
	game.moves = 0;
	mlx_hook(game.win, 2, 0, &key_input, &game);
	mlx_hook(game.win, 17, 0, &game_exit, &game);
	mlx_loop_hook(game.mlx, &frame_update, &game);
	mlx_loop(game.mlx);
	///imgs->d_imgs[0] = mlx_xpm_file_to_image(mlx, "enemy", &mlx->weight, &mlx->height);
	//mlx_put_image_to_window();
	return (0);
}
