#ifndef CORE_BONUS_H
# define CORE_BONUS_H
# include "../so_long.h"

enum e_keys
{
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	RESET = 15,
	ESC = 53
};
typedef struct s_render_info{
	t_pair	coord;
	int		iy;
	int		ix;
}t_render_info;
int		key_input(int key, t_game *game);
void	alloc_img(t_game *game);
int		init_game(t_game *game);
int		frame_update(t_game *game);
void	render(t_game *g);
void	alloc_player_img(t_game *game);
void	alloc_dead_img(t_game *game);
void	player_die(t_game *g);
void	render_dying_msg(t_game *game);
#endif
