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

static void	alloc_enemy_img(t_game *game)
{
	game->imgs.e_imgs[0] = mlx_xpm_file_to_image(game->mlx, \
	"textures/enemy/1.xpm", &(game->img_size), &(game->img_size));
	game->imgs.e_imgs[1] = mlx_xpm_file_to_image(game->mlx, \
	"textures/enemy/2.xpm", &(game->img_size), &(game->img_size));
	game->imgs.e_imgs[2] = mlx_xpm_file_to_image(game->mlx, \
	"textures/enemy/3.xpm", &(game->img_size), &(game->img_size));
}

static void	alloc_item_img(t_game *game)
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
}

static void	alloc_etc_img(t_game *game)
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
}

void	alloc_img(t_game *game)
{
	game->img_size = 64;
	game->light_size_y = WIN_Y;
	game->light_size_x = WIN_X;
	alloc_player_img(game);
	alloc_dead_img(game);
	alloc_etc_img(game);
	alloc_item_img(game);
	alloc_enemy_img(game);
}
