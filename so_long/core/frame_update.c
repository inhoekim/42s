/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:31:10 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/30 18:26:07 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../map/map.h"
#include "core.h"

static void	player_update(t_game *game)
{
	(game->player.frame)++;
	if (game->player.frame == 5)
	{
		game->player.img_idx = (game->player.img_idx + 1) % 10;
		game->player.frame = 0;
	}
}

static void	etc_update(t_game *game)
{
	(game->item.frame)++;
	if (game->item.frame == 5)
	{
		game->item.img_idx = (game->item.img_idx + 1) % 6;
		game->item.frame = 0;
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

int	frame_update(t_game *game)
{
	player_update(game);
	etc_update(game);
	render(game);
	return (FT_TRUE);
}
