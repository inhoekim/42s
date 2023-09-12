/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:31:16 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/28 15:31:17 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map/map.h"
#include "core.h"

int	init_game(t_game *game)
{
	game->player.curr = get_map()->player;
	game->player.frame = 0;
	game->player.img_idx = 0;
	game->item.frame = 0;
	game->item.cnt = 0;
	game->item.img_idx = 0;
	game->moves = 0;
	game->bright_lv = 1;
	game->dark_cnt = 0;
	game->enemy_lst.next = FT_NULL;
	alloc_img(game);
	return (FT_TRUE);
}
