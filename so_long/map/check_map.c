/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 01:39:21 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/21 01:39:23 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	chk_wall(void)
{
	int		idx;
	t_map	*m;

	idx = -1;
	m = get_map();
	while (++idx < m->info.size.x)
		if ((m->map)[0][idx] != '1' || (m->map)[m->info.size.y - 1][idx] != '1')
			return (FT_ERR);
	idx = -1;
	while (++idx < m->info.size.y)
		if ((m->map)[idx][0] != '1' || (m->map)[idx][m->info.size.x - 1] != '1')
			return (FT_ERR);
	return (FT_TRUE);
}

static void	make_map_info(void)
{
	t_map	*m;
	char	ch;
	int		idx_y;
	int		idx_x;

	idx_y = -1;
	m = get_map();
	while (++idx_y < m->info.size.y)
	{
		idx_x = -1;
		while (++idx_x < m->info.size.x)
		{
			ch = (m->map)[idx_y][idx_x];
			if (ch == 'P')
			{
				m->player.y = idx_y;
				m->player.x = idx_x;
				m->info.player_cnt++;
			}
			if (ch == 'E')
				m->info.exit_cnt++;
			if (ch == 'C')
				m->info.target_cnt++;
		}
	}
}

int	chk_format(void)
{
	t_map	*m;

	if (chk_wall() == FT_ERR)
		return (FT_ERR);
	m = get_map();
	make_map_info();
	if (m->info.exit_cnt != 1 || m->info.player_cnt != 1 \
	|| m->info.target_cnt < 1)
		return (FT_ERR);
	return (FT_TRUE);
}

static int	chk_element(t_dfs_info *d)
{
	if (d->ch == '1')
		return (1);
	else if (d->ch == 'E')
		d->visited_exit++;
	else if (d->ch == 'C')
		d->taget_cnt++;
	return (0);
}

t_dfs_info	*chk_path(t_pair curr, t_dfs_info *d)
{
	int			idx;
	char		**map;
	const int	dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	map = get_map()->map;
	map[curr.y][curr.x] |= MSB;
	idx = -1;
	while (++idx < 4)
	{
		d->ny = curr.y + dirs[idx][0];
		d->nx = curr.x + dirs[idx][1];
		d->ch = map[d->ny][d->nx] & ~MSB;
		if ((map[d->ny][d->nx] & MSB) >> 7 || chk_element(d))
			continue ;
		d->nc.y = d->ny;
		d->nc.x = d->nx;
		chk_path(d->nc, d);
	}
	return (d);
}
