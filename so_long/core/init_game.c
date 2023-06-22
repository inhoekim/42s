
#include "../so_long.h"
#include "../map/map.h"
#include "core.h"
#include <stdlib.h>

static int	push_enemy(t_game *game,\
int y, int x, int dir)
{
	t_enemy	*enemy;
	t_enemy	*iter;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (enemy == FT_NULL)
		return (FT_ERR);
	enemy->curr.y = y;
	enemy->curr.x = x;
	enemy->dir = dir;
	enemy->next = FT_NULL;
	iter = &game->enemy_lst;
	while (iter->next != FT_NULL)
		iter = iter->next;
	iter->next = enemy;
	return (FT_TRUE);
}

static int	alloc_enemy_lst(t_game *game)
{
	int		y;
	int		x;
	t_map	*m;

	m = get_map();
	y = 0;
	while (y < m->info.size.y)
	{
		x = 0;
		while (x < m->info.size.x)
		{
			if (m->map[y][x] == 'H')
				if (push_enemy(game, y, x, 0))
					return (FT_ERR);
			if (m->map[y][x] == 'V')
				if (push_enemy(game, y, x, 1))
					return (FT_ERR);
		}
	}
	return (FT_TRUE);
}

int	init_game(t_game *game)
{
	if (alloc_enemy_lst(game) == FT_ERR)
		return (FT_ERR);
	game->player.curr = get_map()->player;
	game->player.is_dead = 0;
	game->player.frame = 0;
	alloc_img(game);
	game->enemy_lst.next = FT_NULL;
	game->enemy_lst.frame = 0;
	game->item.frame = 0;
	game->item.cnt = 0;
	game->moves = 0;
	game->bright_lv = 2;
	game->dark_cnt = 0;
	return (FT_TRUE);
}