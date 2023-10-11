/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:45:41 by inhkim            #+#    #+#             */
/*   Updated: 2023/10/11 14:36:14 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include "../map_bonus/map_bonus.h"
#include "../utils_bonus/utils_bonus.h"
#include "core_bonus.h"

static void	player_update(t_game *game)
{
	if (game->player.is_dead && game->player.img_idx == 11)
		return ;
	(game->player.frame)++;
	if (!game->player.is_dead)
	{
		if (game->player.frame == 5)
		{
			game->player.img_idx = (game->player.img_idx + 1) % 10;
			game->player.frame = 0;
		}
	}
	else
	{
		if (game->player.frame == 5)
		{
			game->player.img_idx = (game->player.img_idx + 1) % 12;
			game->player.frame = 0;
		}
	}
}

static void	etc_update(t_game *game)
{
	(game->item.frame)++;
	(game->enemy_lst.frame)++;
	if (game->item.frame == 5)
	{
		game->item.img_idx = (game->item.img_idx + 1) % 6;
		game->item.frame = 0;
	}
	if (game->enemy_lst.frame == 6)
	{
		game->enemy_lst.img_idx = (game->enemy_lst.img_idx + 1) % 3;
		game->enemy_lst.frame = 0;
	}
	if (game->bright_lv != 0)
	{
		game->dark_cnt++;
		if (game->dark_cnt == 300)
		{
			(game->bright_lv)--;
			game->dark_cnt = 0;
		}
	}
}

static void	modify_data(t_enemy *e, int ny, int nx)
{
	(get_map()->map)[e->curr.y][e->curr.x] = '0';
	(get_map()->map)[ny][nx] = e->type;
	e->curr.y = ny;
	e->curr.x = nx;
}

static void	move_enemy(t_game *g, \
t_enemy *e, const int dirs[4][2])
{
	t_pair	n;

	while (e != FT_NULL)
	{
		n.y = e->curr.y + dirs[e->dir][0];
		n.x = e->curr.x + dirs[e->dir][1];
		if ((get_map()->map)[n.y][n.x] == 'P' && !g->player.is_dead)
		{
			player_die(g);
			return ;
		}
		if ((get_map()->map)[n.y][n.x] != '0')
		{
			e->dir = (e->dir + 2) % 4;
			n.y = e->curr.y + dirs[e->dir][0];
			n.x = e->curr.x + dirs[e->dir][1];
		}
		if ((get_map()->map)[n.y][n.x] != '0')
		{
			e = e->next;
			continue ;
		}
		modify_data(e, n.y, n.x);
		e = e->next;
	}
}

int	frame_update(t_game *game)
{
	const int	dirs[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

	(game->enemy_move_delay)++;
	if (game->enemy_move_delay == 20)
	{
		move_enemy(game, game->enemy_lst.next, dirs);
		game->enemy_move_delay = 0;
	}
	player_update(game);
	etc_update(game);
	render(game);
	return (FT_TRUE);
}
