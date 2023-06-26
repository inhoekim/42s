
#include "../so_long.h"

static void	alloc_player_img(t_game *game)
{
	game->imgs.p_imgs[0] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/1.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[1] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/2.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[2] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/3.xpm", &(game->img_size), &(game->img_size));
}

static void	alloc_enemy_img(t_game *game)
{
	game->imgs.e_imgs[0] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/enemy/1.xpm", &(game->img_size), &(game->img_size));
	game->imgs.e_imgs[1] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/enemy/2.xpm", &(game->img_size), &(game->img_size));
	game->imgs.e_imgs[2] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/enemy/3.xpm", &(game->img_size), &(game->img_size));
}

static void	alloc_item_img(t_game *game)
{
	game->imgs.i_imgs[0] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/fire/1.xpm", &(game->img_size), &(game->img_size));
	game->imgs.i_imgs[1] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/fire/2.xpm", &(game->img_size), &(game->img_size));
	game->imgs.i_imgs[2] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/fire/3.xpm", &(game->img_size), &(game->img_size));
	game->imgs.i_imgs[3] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/fire/4.xpm", &(game->img_size), &(game->img_size));
	game->imgs.i_imgs[4] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/fire/5.xpm", &(game->img_size), &(game->img_size));
	game->imgs.i_imgs[5] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/fire/6.xpm", &(game->img_size), &(game->img_size));
}

static void	alloc_etc_img(t_game *game)
{
	game->imgs.b_imgs[2] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/light/1.xpm", &(game->light_size_x), &(game->light_size_y));
	game->imgs.b_imgs[1] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/light/2.xpm", &(game->light_size_x), &(game->light_size_y));
	game->imgs.b_imgs[0] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/light/3.xpm", &(game->light_size_x), &(game->light_size_y));
	game->imgs.d_imgs[0] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/etc/dc.xpm", &(game->img_size), &(game->img_size));
	game->imgs.d_imgs[1] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/etc/do.xpm", &(game->img_size), &(game->img_size));
	game->imgs.w_img = mlx_xpm_file_to_image\
	(game->mlx, "imgs/etc/wall.xpm", &(game->img_size), &(game->img_size));
}

void	alloc_img(t_game *game)
{
	game->img_size = 64;
	game->light_size_y = WIN_Y;
	game->light_size_x = WIN_X;
	alloc_player_img(game);
	alloc_etc_img(game);
	alloc_item_img(game);
	alloc_enemy_img(game);
}