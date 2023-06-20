/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 01:39:38 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/21 01:39:38 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../so_long.h"
#include <stdlib.h>

t_map	*get_map()
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
