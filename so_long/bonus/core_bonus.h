/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:03:21 by inhkim            #+#    #+#             */
/*   Updated: 2023/07/08 09:03:22 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_BONUS_H
# define CORE_BONUS_H
# include "../so_long_bonus.h"

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
}	t_render_info;
int		key_input(int key, t_game *game);
int		alloc_img(t_game *game);
int		init_game(t_game *game);
int		frame_update(t_game *game);
void	render(t_game *g);
int		alloc_player_img(t_game *game);
int		alloc_dead_img(t_game *game);
void	player_die(t_game *g);
#endif
