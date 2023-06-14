#include <fcntl.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"
#include "map/map.h"
#include "utils/utils.h"
#include "so_long.h"

static void	regist_size(char **file)
{
	int		fd;
	char	*str;
	int 	idx;

	idx = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	get_map()->info.size.x = ft_strlen(str, '\n');
	while (str != FT_NULL)
	{
		if (ft_strlen(str, '\n') != get_map()->info.size.x)
		{
			idx = -1;
			free(str);
			break ;
		}
		free(str);
		idx++;
		str = get_next_line(fd);
	}
	get_map()->info.size.y = idx;
}

static int	alloc_map(char **file)
{
	int 	fd;
	int 	idx;
	char	*str;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	idx = 0;
	while (str != FT_NULL)
	{
		(get_map()->map)[idx] = (char *)malloc(sizeof(char *) * get_map()->info.size.x);
		if ((get_map()->map)[idx] == FT_NULL || \
		chk_str((get_map()->map)[idx], str) == FT_ERR)
		{
			clear_map(idx);
			free(str);
			return (FT_ERR);
		}
		free(str);
		str = get_next_line(fd);
		idx++;
	}
	return (FT_TRUE);
}

static int chk_d(t_dfs_info *d)
{
	if (!(d->visited_exit) || d->taget_cnt != get_map()->info.target_cnt)
		return (FT_ERR);
	return (FT_TRUE);
}

int	create_map(char **file)
{
	t_dfs_info	d;

	regist_size(file);
	if (get_map()->info.size.y <= 0 || get_map()->info.size.x <= 0)
		return (FT_ERR);
	get_map()->map = (char **)malloc(sizeof(char*) * get_map()->info.size.y);
	if (get_map()->map == FT_NULL)
		return (FT_ERR);
	if (alloc_map(file) == FT_ERR)
		return (FT_ERR);
	d.taget_cnt = 0;
	d.visited_exit = 0;
	if (chk_format() == FT_ERR || chk_d(chk_path(get_map()->player, &d)) == FT_ERR)
	{
		clear_map(get_map()->info.size.y - 1);
		return (FT_ERR);
	}
	return (FT_TRUE);
}
