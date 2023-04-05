/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:47:03 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 10:47:06 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_printf_bonus.h>

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
