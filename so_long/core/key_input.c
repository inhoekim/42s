/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:06:29 by inhkim            #+#    #+#             */
/*   Updated: 2023/07/08 09:36:19 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map/map.h"
#include "core.h"
#include "../utils/utils.h"
#include <unistd.h>
#include <stdlib.h>

static void	modify_data(t_game *g, int y, int x)
{
	if ((get_map()->map)[y][x] == 'C')
	{
		g->item.cnt++;
		if (g->bright_lv != 2)
			g->bright_lv++;
		g->dark_cnt = 0;
	}
	(get_map()->map)[y][x] = 'P';
	(get_map()->map)[g->player.curr.y][g->player.curr.x] = '0';
	get_map()->player.y = y;
	get_map()->player.x = x;
	g->player.curr.y = y;
	g->player.curr.x = x;
}

static void	change_map(t_game *g, int y, int x)
{
	char	*move_str;

	if ((get_map()->map)[y][x] == '1')
		return ;
	g->moves++;
	move_str = ft_itoa(g->moves);
	write(1, &"move_cnt : ", 11);
	write(1, move_str, num_len(g->moves) + 1);
	free(move_str);
	if ((get_map()->map)[y][x] == 'E')
	{
		if (g->item.cnt == get_map()->info.target_cnt)
			game_exit(g);
		else
			return ;
	}
	if ((get_map()->map)[y][x] == 'V' || (get_map()->map)[y][x] == 'H')
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
