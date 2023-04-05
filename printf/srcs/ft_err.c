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

void	ft_err(long long write_cnt, t_check_wdata *data)
{
	if (write_cnt < 0)
		data->is_minus = 1;
	else
		data->cnt += write_cnt;
}
