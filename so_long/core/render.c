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

void	render_player(t_game *g)
{
	//t_map 	*m;
	t_pair	center;

	//m = get_map();
	center.y = WIN_Y / 2;
	center.x = WIN_X / 2;
	mlx_put_image_to_window(g->mlx, g->win, g->imgs.p_imgs[g->player.img_idx], WIN_Y / 2, WIN_X / 2);
}

int	render(t_game *g)
{
	mlx_clear_window(g->mlx, g->win);

	render_player(g);
	//render_bringht();
	return (1);
}