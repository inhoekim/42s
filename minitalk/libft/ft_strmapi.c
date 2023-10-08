/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:53:24 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/18 19:53:26 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		idx;
	int		size;
	char	*new_str;

	size = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * (size + 1));
	if (new_str == FT_NULL)
		return (FT_NULL);
	idx = 0;
	while (s[idx] != 0)
	{		
		new_str[idx] = f(idx, s[idx]);
		idx++;
	}
	new_str[idx] = '\0';
	return (new_str);
}
