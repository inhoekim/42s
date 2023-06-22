
#include "../so_long.h"

static void	player_update()
{

}

int	frame_update(t_game *game)
{
	player_update();
	item_update();
	effect_update();
	enemy_update();
	render();
}