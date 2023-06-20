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
# include <mlx.h>
typedef struct s_pair{
	int	x;
	int	y;
}t_pair;
typedef struct s_player
{
	t_pair		curr;
	int			is_dead;
	int			frame;
}t_player;
typedef struct s_item{
	t_pair	curr;
	int		frame;
}t_item;
typedef struct s_item_lst{
	t_pair	curr;
	int		frame;
}t_item_lst;
typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*img;
	int		weight;
	int		height;
}t_mlx;
typedef struct s_imgs{
	void	*p_imgs[3];
	void	*e_imgs[3];
	void	*d_imgs[2];
	void	*i_imgs[3];
}t_imgs;
typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	int			item_cnt;
	int			moves;
	int			door;
}t_game;
int	game_exit();
#endif
