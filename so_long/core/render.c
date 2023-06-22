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

void	render_player(t_game *g)
{
	mlx_put_image_to_window(g->mlx, g->win,\
	g->imgs.p_imgs[g->player.img_idx], WIN_X / 2, WIN_Y / 2);
	mlx_put_image_to_window(g->mlx, g->win,\
	g->imgs.b_imgs[g->bright_lv], WIN_X / 2, WIN_Y / 2);
}

void	render_map(t_game *g)
{
	t_map	*m;

	int y = g->player.curr.y;
	int x = g->player.curr.x;

	idx = -1;
	while (++idx < 5) {
		idx2 = -1;
		while (++idx2 < 5) {

		}
	}
	for (int i = 0; i < 5; i++)
		for

	m = get_map();
}


int	render(t_game *g)
{
	mlx_clear_window(g->mlx, g->win);

	render_player(g);
	return (1);
}