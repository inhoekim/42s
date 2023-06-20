/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:06:29 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/21 02:37:34 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "core.h"

int	key_input(int key)
{
	if (key == ESC)
	{
		game_exit();
	}
	/*
	else if (key == UP || key == DOWN || \
	key == LEFT || key == RIGHT)
		move_p(key);
	else if (key == RESET)
		game_reset();
	*/
	return (-1);
}
