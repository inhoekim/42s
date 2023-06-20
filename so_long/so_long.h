#ifndef SO_LONG_H
 # define SO_LONG_H
 # define FT_NULL 0
 # define FT_TRUE 1
 # define FT_ERR -1

typedef struct s_pair{
	int	x;
	int	y;
}t_pair;
typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	int		action_frames;
	void	*action_img;
}t_player;
typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_pair			wd_size;
	t_tile			**tilemap;
	t_player		player;
	int				og_collects;
	int				collects;
	int				moves;
	t_enemy			*enemy_list;
	t_vector		img_size;
	t_wall_img		wall_imgs;
	t_collect_img	collects_imgs;
	t_enemy_img		enemy_imgs;
	void			*door_open_img;
	void			*door_close_img;
	t_effect		effect;
	void			*red_panel;
	void			*white_panel;
}t_game;

#endif