/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:03:21 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/13 20:24:18 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	if (s == FT_NULL)
		return (0);
	while (s[idx] != '\0')
		idx++;
	return (idx);
}
