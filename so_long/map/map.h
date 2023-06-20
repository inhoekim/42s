/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 01:39:41 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/21 03:46:30 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
 # define MAP_H
 # define MSB (0x80)
 # include "../so_long.h"
typedef struct s_map_info{
	int		player_cnt;
	int		target_cnt;
	int		exit_cnt;
	t_pair	size;
}t_map_info;
typedef struct s_map{
	t_map_info	info;
	t_pair	player;
	int		can_exit;
	char	**map;
}t_map;
typedef struct s_dfs_info{
	int		ny;
	int		nx;
	int		taget_cnt;
	int		visited_exit;
	char	ch;
	t_pair	nc;
}t_dfs_info;
t_map		*get_map();
int			create_map(char *file);
void		clear_map(int cnt);
int			chk_format();
t_dfs_info	*chk_path(t_pair curr, t_dfs_info *d);
#endif
