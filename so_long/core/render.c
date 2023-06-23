/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:05:06 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/21 00:05:07 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../map/map.h"
#include "core.h"

/*
void	render_element(char type)
{
	if (type == 'V' || type == 'H') {

	}
	else if (type == '1') {

	}
	else if (type == '')
}
*/

static void	render_element(t_game *g, int dy, int dx)
{
	t_map	*m;
	char	type;
	int 	center_x;
	int 	center_y;

	m = get_map();
	if (m->player.y + dy < 0 || m->player.y + dy >= m->info.size.y || \
	m->player.x + dx < 0 || m->player.x + dx >= m->info.size.x)
		return ;
	center_x = (WIN_X / 2) - (g->img_size / 2);
	center_y = (WIN_Y / 2) - (g->img_size / 2);
	type = (m->map)[m->player.y + dy][m->player.x + dx];
	if (type == '1')
		mlx_put_image_to_window(g->mlx, g->win,\
	g->imgs.w_img, center_x + dx * 64, center_y + dy * 64);
}

static void	render_player(t_game *g)
{
	mlx_put_image_to_window(g->mlx, g->win,\
	g->imgs.p_imgs[g->player.img_idx], \
	(WIN_X / 2) - g->img_size / 2, (WIN_Y / 2) - g->img_size / 2);
	mlx_put_image_to_window(g->mlx, g->win,\
	g->imgs.b_imgs[g->bright_lv], 0, 0);
}

static void	render_map(t_game *g)
{
	t_render_info	ri;

	ri.iy = 0;
	while (++ri.iy <= 4) {
		render_element(g, -ri.iy, 0);
		if (ri.iy != 4)
			render_element(g, ri.iy, 0);
	}
	ri.ix = 0;
	while (++ri.ix <= 8) {
		render_element(g, 0, ri.ix);
		if (ri.ix != 8)
			render_element(g, 0, -ri.ix);
	}

}

int	render(t_game *g)
{
	mlx_clear_window(g->mlx, g->win);
	render_player(g);
	render_map(g);
	return (1);
}