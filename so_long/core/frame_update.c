
#include "../so_long.h"
#include "core.h"

static void	player_update(t_game *game)
{
	if (!game->player.is_dead)
	{
		(game->player.frame)++;
		if (game->player.frame == 12)
		{
			game->player.img_idx = (game->player.img_idx + 1) % 3;
			game->player.frame = 0;
		}
	}
}

static void	etc_update(t_game *game)
{
	(game->item.frame)++;
	(game->enemy_lst.frame)++;
	if (game->item.frame == 6)
	{
		game->item.img_idx = (game->item.img_idx + 1) % 6;
		game->item.frame = 0;
	}
	if (game->enemy_lst.frame == 12)
	{
		game->enemy_lst.img_idx = (game->enemy_lst.img_idx + 1) % 3;
		game->enemy_lst.frame = 0;
	}
}

static void	bright_update(t_game *game)
{
	game->dark_cnt++;
	if (game->dark_cnt == 250)
	{
		(game->bright_lv)--;
		game->dark_cnt = 0;
	}
}

static void	enemy_move()
{

}

int	frame_update(t_game *game)
{
	player_update(game);
	etc_update(game);
	if (game->bright_lv != 0)
		bright_update(game);
	enemy_move();
	render(game);
	return (FT_TRUE);
}