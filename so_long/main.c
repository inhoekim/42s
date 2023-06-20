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

void	alloc_img(t_game *game)
{
	game->imgs.p_imgs[0] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/1.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[1] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/2.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[2] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/3.xpm", &(game->img_size), &(game->img_size));
	game->imgs.i_imgs[0] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/fire/1.xpm", &(game->img_size), &(game->img_size));		
	game->imgs.i_imgs[1] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/fire/2.xpm", &(game->img_size), &(game->img_size));
	game->imgs.i_imgs[2] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/fire/3.xpm", &(game->img_size), &(game->img_size));
}

int	render(t_game *g)
{
	if (g->player.frame == 0 || g->player.frame == 30 || g->moves == 0 || g->moves == 20 || g->moves == 40)
		mlx_clear_window(g->mlx, g->win);
	if (g->player.frame <= 30)
		mlx_put_image_to_window(g->mlx, g->win, g->imgs.p_imgs[1], 0, 0);
	else if (g->player.frame <= 60)
		mlx_put_image_to_window(g->mlx, g->win, g->imgs.p_imgs[2], 0, 0);
	else
		g->player.frame = 0;
	g->player.frame++;

	if (g->moves <= 20)
		mlx_put_image_to_window(g->mlx, g->win, g->imgs.i_imgs[0], 128, 0);
	else if (g->player.frame <= 40)
		mlx_put_image_to_window(g->mlx, g->win, g->imgs.i_imgs[1], 128, 0);
	else if (g->player.frame <= 60)
		mlx_put_image_to_window(g->mlx, g->win, g->imgs.i_imgs[2], 128, 0);		
	else
		g->moves = 0;
	g->moves++;
	return (1);
}

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
		ft_printf("[Error] abnormal map file\n");
		return (1);
	}
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1000, 600, "so_long");
	alloc_img(&game);
	game.moves = 0;
	mlx_hook(game.win, 2, 0, &key_input, &game);
	mlx_hook(game.win, 17, 0, &game_exit, &game);
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_loop(game.mlx);
	///imgs->d_imgs[0] = mlx_xpm_file_to_image(mlx, "enemy", &mlx->weight, &mlx->height);
	//mlx_put_image_to_window();
	return (0);
}
