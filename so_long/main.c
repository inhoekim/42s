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
#include <stdlib.h>
#include <unistd.h>

static void	free_all(t_game *g)
{
	int		i;
	t_enemy	*iter;
	t_enemy	*next_iter;

	i = -1;
	while (++i < get_map()->info.size.y)
		free((get_map()->map)[i]);
	free(get_map()->map);
	iter = g->enemy_lst.next;
	while (iter != FT_NULL)
	{
		next_iter = iter->next;
		free(iter);
		iter = next_iter;
	}
}

static void	game_start(t_game *game)
{
	game->mlx = mlx_init();
	if (init_game(game) == FT_ERR)
	{
		perror("[Error] allocation failed");
		exit (1);
	}
	game->win = mlx_new_window(game->mlx, WIN_X, WIN_Y, "so_long");
	mlx_hook(game->win, 3, 0, &key_input, game);
	mlx_hook(game->win, 17, 0, &game_exit, game);
	mlx_loop_hook(game->mlx, &frame_update, game);
	mlx_loop(game->mlx);
}

static int	chk_file_format(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != FT_NULL)
		idx++;
	idx -= 4;
	if (str[idx] == '.' && \
	str[idx + 1] == 'b' && str[idx + 2] == 'e' && str[idx + 3] == 'r')
		return (FT_TRUE);
	return (FT_ERR);
}

int	game_exit(t_game *game)
{
	free_all(game);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || chk_file_format(argv[1]) == FT_ERR)
	{
		write(2, &"[Error] wrong file name\n", 24);
		exit (1);
	}
	if (create_map(argv[1]) == FT_ERR)
	{
		write(2, &"[Error] abnormal map file\n", 26);
		exit (1);
	}
	game_start(&game);
	return (game_exit(&game));
}
