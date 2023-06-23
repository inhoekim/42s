
#include "../so_long.h"
#include "core.h"

static void	player_update(t_game *game)
{
	if (!game->player.is_dead)
	{
		(game->player.frame)++;
		if (game->player.frame == 15)
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
	if (game->item.frame == 15)
		game->item.img_idx = (game->item.img_idx + 1) % 3;
	if (game->enemy_lst.frame == 15)
		game->enemy_lst.img_idx = (game->enemy_lst.img_idx + 1) % 3;
}

static void	bright_update(t_game *game)
{
	game->dark_cnt++;
	if (game->dark_cnt == 100)
	{
		(game->bright_lv)--;
		game->dark_cnt = 0;
	}
}

int	frame_update(t_game *game)
{
	player_update(game);
	etc_update(game);
	//effect_update();
	if (game->bright_lv != 0)
		;//bright_update(game);
	render(game);
	return (FT_TRUE);
}