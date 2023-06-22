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


int	render(t_game *g)
{
	if (g->player.frame == 0 || g->player.frame == 30 || g->moves == 0 || g->moves == 20 || g->moves == 40)
		mlx_clear_window(g->mlx, g->win);
	if (g->player.frame <= 30)
		mlx_put_image_to_window(g->mlx, g->win, g->imgs.p_imgs[1], 0, 0);
	else if (g->player.frame <= 60)
		mlx_put_image_to_window(g->mlx, g->win, g->imgs.p_imgs[2], 0, 0);
	else
		g->player.frame = 0;
	g->player.frame++;

	if (g->moves <= 20)
		mlx_put_image_to_window(g->mlx, g->win, g->imgs.i_imgs[0], 128, 0);
	else if (g->player.frame <= 40)
		mlx_put_image_to_window(g->mlx, g->win, g->imgs.i_imgs[1], 128, 0);
	else if (g->player.frame <= 60)
		mlx_put_image_to_window(g->mlx, g->win, g->imgs.i_imgs[2], 128, 0);
	else
		g->moves = 0;
	g->moves++;
	return (1);
}