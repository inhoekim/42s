/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:38:57 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/21 02:36:47 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H
#include "../so_long.h"
enum e_keys
{
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	RESET = 15,
	ESC = 53
};
int		key_input(int key);
void	alloc_img(t_game *game);
int		init_game(t_game *game);
int		frame_update(t_game *game);
int		render(t_game *g);
#endif
