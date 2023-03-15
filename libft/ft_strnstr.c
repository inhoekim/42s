/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:36:26 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/14 14:36:27 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	hay_idx;
	int	need_idx;

	hay_idx = 0;
	need_idx = 0;
	while (haystack[hay_idx])
	{
		if (needle[need_idx] == 0)
			return ((char *)(haystack + hay_idx - need_idx));
		if (len == 0)
			return (0);
		if (haystack[hay_idx] == needle[need_idx])
			need_idx++;
		else
		{
			hay_idx -= need_idx ;
			len += need_idx;
			need_idx = 0;
		}
		hay_idx++;
		len--;
	}
	if (needle[need_idx] == 0)
		return ((char *)haystack + hay_idx - need_idx);
	return (0);
}
