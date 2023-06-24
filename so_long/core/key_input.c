/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:06:29 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/21 02:37:34 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../map/map.h"
#include "core.h"

static void	change_map(t_game *g, int y, int x)
{
	if ((get_map()->map)[y][x] == '1')
		return ;
	
}

static void	move_player(t_game *g, int key)
{
	if (key == UP)
		change_map(g, g->player.curr.y - 1, g->player.curr.x);
}

int	key_input(int key, t_game *g)
{
	if (key == ESC)
		game_exit();
	if (key == UP || key == DOWN || \
	key == LEFT || key == RIGHT)
		move_player(g, key);
	/*
	else if (key == RESET)
		game_reset();
	 */
	return (FT_TRUE);
}
