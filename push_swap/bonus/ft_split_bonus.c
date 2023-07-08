/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 03:16:16 by inhkim            #+#    #+#             */
/*   Updated: 2023/06/19 14:50:01 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	if (dstsize == 0)
		return ;
	while (src[idx] && (idx < dstsize - 1))
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
}

static	int	get_split_cnt(char const *s)
{
	int	idx;
	int	cnt;

	cnt = 0;
	idx = 0;
	while (s[idx])
	{
		if ((9 <= s[idx] && s[idx] <= 13) || s[idx] == 32)
			while (s[idx] && ((9 <= s[idx] && s[idx] <= 13) || s[idx] == 32))
				idx++;
		else
		{
			cnt++;
			while (s[idx] && !((9 <= s[idx] && s[idx] <= 13) || s[idx] == 32))
				idx++;
		}
	}
	return (cnt);
}

static	int	make_each_str(char	**new_strs, char const *s, int idx)
{	
	int		strs_cnt;
	int		str_len;

	strs_cnt = 0;
	while (s[idx] != '\0')
	{
		str_len = 0;
		if ((9 <= s[idx] && s[idx] <= 13) || s[idx] == 32)
			while (s[idx] && ((9 <= s[idx] && s[idx] <= 13) || s[idx] == 32))
				idx++;
		else
		{
			while (s[idx] && (!(9 <= s[idx] && s[idx] <= 13) && s[idx] != 32))
			{
				str_len++;
				idx++;
			}
			new_strs[strs_cnt] = (char *)malloc(sizeof(char) * (str_len + 1));
			if (new_strs[strs_cnt] == FT_NULL)
				return (strs_cnt * -1);
			ft_strlcpy(new_strs[strs_cnt++], s + idx - str_len, str_len + 1);
		}
	}
	return (1);
}

static void	free_all(char **new_strs, int strs_cnt)
{
	int	idx;

	idx = 0;
	while (idx < strs_cnt)
	{
		free(new_strs[idx]);
		idx++;
	}
	free(new_strs);
}

char	**ft_split(const char *s)
{
	char	**new_strs;
	int		strs_cnt;

	strs_cnt = get_split_cnt(s);
	new_strs = (char **)malloc(sizeof(char *) * (strs_cnt + 1));
	if (strs_cnt == 0 || new_strs == FT_NULL)
	{
		free(new_strs);
		return (FT_NULL);
	}
	new_strs[strs_cnt] = FT_NULL;
	strs_cnt = make_each_str(new_strs, s, 0);
	if (strs_cnt <= 0)
	{
		free_all(new_strs, strs_cnt * -1);
		return (FT_NULL);
	}
	return (new_strs);
}
