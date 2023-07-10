/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:03:41 by inhkim            #+#    #+#             */
/*   Updated: 2023/07/10 10:34:00 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map/map.h"
#include "core_bonus.h"

static void	modify_data(t_game *g, int y, int x)
{
	char	**m;

	m = get_map()->map;
	if (m[y][x] == 'C')
	{
		g->item.cnt++;
		if (g->bright_lv != 2)
			g->bright_lv++;
		g->dark_cnt = 0;
	}
	if (m[y][x] != 'E')
		(get_map()->map)[y][x] = 'P';
	if (m[g->player.curr.y][g->player.curr.x] != 'E')
		(get_map()->map)[g->player.curr.y][g->player.curr.x] = '0';
	get_map()->player.y = y;
	get_map()->player.x = x;
	g->player.curr.y = y;
	g->player.curr.x = x;
}

static void	change_map(t_game *g, int y, int x)
{
	char	**m;

	m = get_map()->map;
	if (m[y][x] == '1' || \
	(m[y][x] == 'E' && g->item.cnt != get_map()->info.target_cnt))
		return ;
	g->moves++;
	if (m[y][x] == 'E')
		game_exit(g);
	if (m[y][x] == 'V' || m[y][x] == 'H')
	{
		player_die(g);
		return ;
	}
	modify_data(g, y, x);
}

static void	move_player(t_game *g, int key)
{
	if (key == UP)
		change_map(g, g->player.curr.y - 1, g->player.curr.x);
	else if (key == DOWN)
		change_map(g, g->player.curr.y + 1, g->player.curr.x);
	else if (key == LEFT)
		change_map(g, g->player.curr.y, g->player.curr.x - 1);
	else if (key == RIGHT)
		change_map(g, g->player.curr.y, g->player.curr.x + 1);
}

void	player_die(t_game *g)
{
	g->player.is_dead = FT_TRUE;
	g->player.frame = 0;
	g->player.img_idx = 0;
}

int	key_input(int key, t_game *g)
{
	if (key == ESC)
		game_exit(g);
	if ((key == UP || key == DOWN || \
	key == LEFT || key == RIGHT) && !g->player.is_dead)
		move_player(g, key);
	return (FT_TRUE);
}
