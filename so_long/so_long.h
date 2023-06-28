/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 01:38:38 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/21 01:38:39 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define FT_NULL 0
# define FT_TRUE 1
# define FT_ERR -1
# define WIN_X 1024
# define WIN_Y 640
# include "mlx/mlx.h"
# include <stdio.h>

typedef struct s_pair{
	int	x;
	int	y;
}t_pair;
typedef struct s_player
{
	t_pair		curr;
	int			is_dead;
	int			img_idx;
	int			frame;
}t_player;
typedef struct s_enemy{
	t_pair			curr;
	int				dir;
	int				img_idx;
	int				frame;
	char			type;
	struct s_enemy	*next;
}t_enemy;
typedef struct s_item{
	int	img_idx;
	int	frame;
	int	cnt;
}t_item;
typedef struct s_imgs{
	void	*p_imgs[10];
	void	*e_imgs[3];
	void	*d_imgs[2];
	void	*i_imgs[6];
	void	*w_img;
	void	*b_imgs[3];
	void	*dead_imgs[12];
}t_imgs;
typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_imgs			imgs;
	t_player		player;
	t_item			item;
	t_enemy			enemy_lst;
	int				img_size;
	int				light_size_y;
	int				light_size_x;
	int				bright_lv;
	int				dark_cnt;
	int				enemy_move_delay;
	unsigned long	moves;
}t_game;
int	game_exit(t_game *game);
#endif
