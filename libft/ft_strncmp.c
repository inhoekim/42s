/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 06:26:51 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/14 06:47:43 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;
	int		diff_flag;

	diff_flag = 0;
	idx = 0;
	if (n == 0)
		return (0);
	while (s1[idx] && s2[idx] && (idx < n))
	{
		if (s1[idx] != s2[idx])
		{
			diff_flag = 1;
			break ;
		}
		idx++;
	}
	if (idx == n || (unsigned char)s1[idx] == (unsigned char)s2[idx])
		return (0);
	if ((unsigned char)s1[idx] > (unsigned char)s2[idx])
		return (1);
	return (-1);
}
