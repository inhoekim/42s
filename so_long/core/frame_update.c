
#include "../so_long.h"
#include "../map/map.h"
#include "core.h"

static void	player_update(t_game *game)
{
	(game->player.frame)++;
	if (!game->player.is_dead)
	{
		if (game->player.frame == 12)
		{
			game->player.img_idx = (game->player.img_idx + 1) % 10;
			game->player.frame = 0;
		}
	}
	else
	{
		if (game->player.frame == 12)
		{
			game->player.img_idx = (game->player.img_idx + 1) % 14;
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
	if (game->bright_lv != 0)
	{
		game->dark_cnt++;
		if (game->dark_cnt == 250)
		{
			(game->bright_lv)--;
			game->dark_cnt = 0;
		}
	}
}

static void	move_enemy(t_game *g, \
int ny, int nx, const int dirs[4][2])
{
	t_enemy *e;
	
	e = g->enemy_lst.next;
	while (e != FT_NULL)
	{
		ny = e->curr.y + dirs[e->dir][0];
		nx = e->curr.x + dirs[e->dir][1];
		if ((get_map()->map)[ny][nx] == 'P')
			player_die(g);
		if ((get_map()->map)[ny][nx] != '0')
		{
			e->dir = (e->dir + 2) % 4;
			ny = e->curr.y + dirs[e->dir][0];
			nx = e->curr.x + dirs[e->dir][1];
		}
		if ((get_map()->map)[ny][nx] != '0')
			return ;
		(get_map()->map)[e->curr.y][e->curr.x] = '0';
		(get_map()->map)[ny][nx] = e->type;
		e->curr.y = ny;
		e->curr.x = nx;
		e = e->next;
	}
}

int	frame_update(t_game *game)
{
	const int	dirs[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

	(game->enemy_move_delay)++;
	player_update(game);
	etc_update(game);
	if (game->enemy_move_delay == 100)
	{
		move_enemy(game, 0, 0, dirs);
		game->enemy_move_delay = 0;
	}
	render(game);
	return (FT_TRUE);
}