/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_img2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:03:06 by inhkim            #+#    #+#             */
/*   Updated: 2023/07/08 09:03:07 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	check_dead_imgs(t_game *game)
{
	if (!game->imgs.dead_imgs[0] || !game->imgs.dead_imgs[1] || \
	!game->imgs.dead_imgs[2] || !game->imgs.dead_imgs[3] || \
	!game->imgs.dead_imgs[4] || !game->imgs.dead_imgs[5] || \
	!game->imgs.dead_imgs[6] || !game->imgs.dead_imgs[7] || \
	!game->imgs.dead_imgs[8] || !game->imgs.dead_imgs[9] || \
	!game->imgs.dead_imgs[10] || !game->imgs.dead_imgs[11])
		return (FT_ERR);
	return (FT_TRUE);
}

static int	check_player_imgs(t_game *game)
{
	if (!game->imgs.p_imgs[0] || !game->imgs.p_imgs[1] || \
	!game->imgs.p_imgs[2] || !game->imgs.p_imgs[3] || \
	!game->imgs.p_imgs[4] || !game->imgs.p_imgs[5] || \
	!game->imgs.p_imgs[6] || !game->imgs.p_imgs[7] || \
	!game->imgs.p_imgs[8] || !game->imgs.p_imgs[9])
		return (FT_ERR);
	return (FT_TRUE);
}

int	alloc_dead_img(t_game *game)
{
	game->imgs.dead_imgs[0] = mlx_xpm_file_to_image(game->mlx, \
	"textures/dead/0.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[1] = mlx_xpm_file_to_image(game->mlx, \
	"textures/dead/1.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[2] = mlx_xpm_file_to_image(game->mlx, \
	"textures/dead/2.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[3] = mlx_xpm_file_to_image(game->mlx, \
	"textures/dead/3.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[4] = mlx_xpm_file_to_image(game->mlx, \
	"textures/dead/4.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[5] = mlx_xpm_file_to_image(game->mlx, \
	"textures/dead/5.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[6] = mlx_xpm_file_to_image(game->mlx, \
	"textures/dead/6.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[7] = mlx_xpm_file_to_image(game->mlx, \
	"textures/dead/7.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[8] = mlx_xpm_file_to_image(game->mlx, \
	"textures/dead/8.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[9] = mlx_xpm_file_to_image(game->mlx, \
	"textures/dead/9.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[10] = mlx_xpm_file_to_image(game->mlx, \
	"textures/dead/10.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[11] = mlx_xpm_file_to_image(game->mlx, \
	"textures/dead/11.xpm", &(game->img_size), &(game->img_size));
	return (check_dead_imgs(game));
}

int	alloc_player_img(t_game *game)
{
	game->imgs.p_imgs[0] = mlx_xpm_file_to_image(game->mlx, \
	"textures/player/0.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[1] = mlx_xpm_file_to_image(game->mlx, \
	"textures/player/1.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[2] = mlx_xpm_file_to_image(game->mlx, \
	"textures/player/2.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[3] = mlx_xpm_file_to_image(game->mlx, \
	"textures/player/3.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[4] = mlx_xpm_file_to_image(game->mlx, \
	"textures/player/4.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[5] = mlx_xpm_file_to_image(game->mlx, \
	"textures/player/5.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[6] = mlx_xpm_file_to_image(game->mlx, \
	"textures/player/6.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[7] = mlx_xpm_file_to_image(game->mlx, \
	"textures/player/7.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[8] = mlx_xpm_file_to_image(game->mlx, \
	"textures/player/8.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[9] = mlx_xpm_file_to_image(game->mlx, \
	"textures/player/9.xpm", &(game->img_size), &(game->img_size));
	return (check_player_imgs(game));
}
