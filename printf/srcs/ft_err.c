/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:44:22 by inhkim            #+#    #+#             */
/*   Updated: 2023/04/05 18:44:24 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_err(long long write_cnt, long long *cnt)
{
	if (write_cnt < 0)
		return (1);
	else
		*cnt += write_cnt;
	return (0);
}
