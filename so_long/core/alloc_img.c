/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:30:50 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/28 15:30:52 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "core.h"

static int	alloc_item_img(t_game *game)
{
	game->imgs.i_imgs[0] = mlx_xpm_file_to_image(game->mlx, \
	"textures/fire/1.xpm", &(game->img_size), &(game->img_size));
	game->imgs.i_imgs[1] = mlx_xpm_file_to_image(game->mlx, \
	"textures/fire/2.xpm", &(game->img_size), &(game->img_size));
	game->imgs.i_imgs[2] = mlx_xpm_file_to_image(game->mlx, \
	"textures/fire/3.xpm", &(game->img_size), &(game->img_size));
	game->imgs.i_imgs[3] = mlx_xpm_file_to_image(game->mlx, \
	"textures/fire/4.xpm", &(game->img_size), &(game->img_size));
	game->imgs.i_imgs[4] = mlx_xpm_file_to_image(game->mlx, \
	"textures/fire/5.xpm", &(game->img_size), &(game->img_size));
	game->imgs.i_imgs[5] = mlx_xpm_file_to_image(game->mlx, \
	"textures/fire/6.xpm", &(game->img_size), &(game->img_size));
	if (!game->imgs.i_imgs[0] || !game->imgs.i_imgs[1] || !game->imgs.i_imgs[2] \
	|| !game->imgs.i_imgs[3] || !game->imgs.i_imgs[4] || !game->imgs.i_imgs[5])
		return (FT_ERR);
	return (FT_TRUE);
}

static int	alloc_etc_img(t_game *game)
{
	game->imgs.b_imgs[2] = mlx_xpm_file_to_image(game->mlx, \
	"textures/light/1.xpm", &(game->light_size_x), &(game->light_size_y));
	game->imgs.b_imgs[1] = mlx_xpm_file_to_image(game->mlx, \
	"textures/light/2.xpm", &(game->light_size_x), &(game->light_size_y));
	game->imgs.b_imgs[0] = mlx_xpm_file_to_image(game->mlx, \
	"textures/light/3.xpm", &(game->light_size_x), &(game->light_size_y));
	game->imgs.d_imgs[0] = mlx_xpm_file_to_image(game->mlx, \
	"textures/etc/dc.xpm", &(game->img_size), &(game->img_size));
	game->imgs.d_imgs[1] = mlx_xpm_file_to_image(game->mlx, \
	"textures/etc/do.xpm", &(game->img_size), &(game->img_size));
	game->imgs.w_img = mlx_xpm_file_to_image(game->mlx, \
	"textures/etc/wall.xpm", &(game->img_size), &(game->img_size));
	if (!game->imgs.b_imgs[0] || !game->imgs.b_imgs[1] || !game->imgs.b_imgs[2] \
	|| !game->imgs.d_imgs[0] || !game->imgs.d_imgs[1] || !game->imgs.w_img)
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

static int	alloc_player_img(t_game *game)
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

int	alloc_img(t_game *game)
{
	game->img_size = 64;
	game->light_size_y = WIN_Y;
	game->light_size_x = WIN_X;
	if (alloc_player_img(game) == FT_ERR || alloc_etc_img(game) == FT_ERR \
	|| alloc_item_img(game) == FT_ERR)
		return (FT_ERR);
	return (FT_TRUE);
}
