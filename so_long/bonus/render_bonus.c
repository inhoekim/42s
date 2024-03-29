/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:03:46 by inhkim            #+#    #+#             */
/*   Updated: 2023/10/11 14:36:43 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map_bonus/map_bonus.h"
#include "core_bonus.h"
#include "../utils_bonus/utils_bonus.h"
#include <stdlib.h>

static void	render_element(t_game *g, int dy, int dx)
{
	t_map	*m;
	char	type;
	int		c_x;
	int		c_y;

	m = get_map();
	if (m->player.y + dy < 0 || m->player.y + dy >= m->info.size.y || \
	m->player.x + dx < 0 || m->player.x + dx >= m->info.size.x)
		return ;
	c_x = (WIN_X / 2) - (g->img_size / 2);
	c_y = (WIN_Y / 2) - (g->img_size / 2);
	type = (m->map)[m->player.y + dy][m->player.x + dx];
	if (type == '1')
		mlx_put_image_to_window(g->mlx, g->win, \
		g->imgs.w_img, c_x + dx * 64, c_y + dy * 64);
	if (type == 'C')
		mlx_put_image_to_window(g->mlx, g->win, \
		g->imgs.i_imgs[g->item.img_idx], c_x + dx * 64, c_y + dy * 64);
	if (type == 'E')
		mlx_put_image_to_window(g->mlx, g->win, \
		g->imgs.d_imgs[(g->item.cnt == get_map()->info.target_cnt)], \
		c_x + dx * 64, c_y + dy * 64);
	if (type == 'V' || type == 'H')
		mlx_put_image_to_window(g->mlx, g->win, \
		g->imgs.e_imgs[g->enemy_lst.img_idx], c_x + dx * 64, c_y + dy * 64);
}

static void	render_player(t_game *g)
{
	if (!g->player.is_dead)
	{
		mlx_put_image_to_window(g->mlx, g->win, \
		g->imgs.p_imgs[g->player.img_idx], \
		(WIN_X / 2) - g->img_size / 2, (WIN_Y / 2) - g->img_size / 2);
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->win, \
		g->imgs.dead_imgs[g->player.img_idx], \
		(WIN_X / 2) - g->img_size / 2, (WIN_Y / 2) - g->img_size / 2);
	}
	mlx_put_image_to_window(g->mlx, g->win, \
	g->imgs.b_imgs[g->bright_lv], 0, 0);
}

static void	render_map(t_game *g)
{
	t_render_info	ri;

	ri.iy = -1;
	while (++ri.iy <= 4)
	{
		ri.ix = -1;
		while (++ri.ix <= 8)
		{
			render_element(g, ri.iy, ri.ix);
			render_element(g, ri.iy, -ri.ix);
		}
	}
	ri.iy = -1;
	while (++ri.iy <= 4)
	{
		ri.ix = -1;
		while (++ri.ix <= 8)
		{
			render_element(g, -ri.iy, ri.ix);
			render_element(g, -ri.iy, -ri.ix);
		}
	}
}

static void	render_dying_msg(t_game *game)
{
	if (game->player.is_dead)
	{
		mlx_string_put(game->mlx, game->win, (WIN_X / 2) - 30, \
		(WIN_Y / 4) * 3, 0x00FF0000, "GAME OVER");
		mlx_string_put(game->mlx, game->win, (WIN_X / 2) - 80, \
		(WIN_Y / 5) * 4, 0x00FF0000, "YOU LOSE... PRESS [ESC] !");
	}
}

void	render(t_game *g)
{	
	char	*move_str;

	mlx_clear_window(g->mlx, g->win);
	render_map(g);
	render_player(g);
	move_str = ft_itoa(g->moves);
	mlx_string_put(g->mlx, g->win, \
		15, 20, 0x00FF0000, move_str);
	free(move_str);
	render_dying_msg(g);
}
