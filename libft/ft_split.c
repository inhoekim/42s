/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:49:40 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/18 13:49:41 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_split_cnt(char const *s, char c)
{
	int	idx;
	int	cnt;

	cnt = 0;
	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == c)
			while (s[idx] && s[idx] == c)
				idx++;
		else
		{
			cnt++;
			while (s[idx] && s[idx] != c)
				idx++;
		}
	}
	return (cnt);
}

static	int	make_each_str(char	**new_strs, char const *s, char c)
{
	int		strs_cnt;
	int		idx;
	int		str_len;

	idx = 0;
	strs_cnt = 0;
	while (s[idx] != '\0')
	{
		str_len = 0;
		if (s[idx] == c)
		{
			idx++;
			continue ;
		}
		while (s[idx] && s[idx] != c)
		{
			idx++;
			str_len++;
		}
		new_strs[strs_cnt] = (char *)malloc(sizeof(char) * (str_len + 1));
		if (new_strs[strs_cnt] == FT_NULL)
			return (strs_cnt * -1);
		ft_strlcpy(new_strs[strs_cnt++], s + idx - str_len, str_len + 1);
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

char	**ft_split(const char *s, char c)
{
	char	**new_strs;
	int		strs_cnt;

	strs_cnt = get_split_cnt(s, c);
	new_strs = (char **)malloc(sizeof(char *) * (strs_cnt + 1));
	if (new_strs == FT_NULL)
		return (FT_NULL);
	new_strs[strs_cnt] = FT_NULL;
	while (*s && *s == c)
		s++;
	strs_cnt = make_each_str(new_strs, s, c);
	if (strs_cnt <= 0)
	{
		free_all(new_strs, strs_cnt * -1);
		return (FT_NULL);
	}
	return (new_strs);
}
