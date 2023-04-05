/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:18:49 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 02:18:50 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

long long	ft_print_percent(t_format format)
{
	if (format.flag_ascii['-'])
	{
		if (write(1, "%", 1) == 1 || \
		ft_print_width(format.width - 1) == -1)
			return (-1);
	}
	else
	{
		if (ft_print_width(format.width - 1) == -1 || \
		write(1, "%", 1) == -1)
			return (-1);
	}
	if (format.width >= 1)
		return (format.width);
	return (1);
}
