/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:30:45 by inhkim            #+#    #+#             */
/*   Updated: 2023/10/11 14:30:47 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"
#include <stdlib.h>

t_map	*get_map(void)
{
	static t_map	map;

	return (&map);
}

void	clear_map(int cnt)
{
	int	idx;

	idx = 0;
	while (idx <= cnt)
	{
		free((get_map()->map)[idx]);
		idx++;
	}
	free(get_map()->map);
}
