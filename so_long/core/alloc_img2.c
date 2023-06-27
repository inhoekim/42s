#include "../so_long.h"

static void	alloc_dead_img2(t_game *game)
{
	game->imgs.dead_imgs[8] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/8.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[9] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/9.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[10] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/10.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[11] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/11.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[12] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/12.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[13] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/13.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[14] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/14.xpm", &(game->img_size), &(game->img_size));
}

void	alloc_dead_img(t_game *game)
{
	game->imgs.dead_imgs[0] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/0.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[1] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/1.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[2] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/2.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[3] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/3.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[4] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/4.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[5] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/5.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[6] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/6.xpm", &(game->img_size), &(game->img_size));
	game->imgs.dead_imgs[7] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/dead/7.xpm", &(game->img_size), &(game->img_size));
	alloc_dead_img2(game);
}

void	alloc_player_img(t_game *game)
{
	game->imgs.p_imgs[0] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/0.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[1] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/1.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[2] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/2.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[3] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/3.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[4] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/4.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[5] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/5.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[6] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/6.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[7] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/7.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[8] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/8.xpm", &(game->img_size), &(game->img_size));
	game->imgs.p_imgs[9] = mlx_xpm_file_to_image\
	(game->mlx, "imgs/player/9.xpm", &(game->img_size), &(game->img_size));
}
