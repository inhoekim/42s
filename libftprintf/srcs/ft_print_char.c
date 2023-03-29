/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:33:19 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/29 08:33:20 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./includes/printft.h"

long long	ft_print_char(t_format format, char ch)
{
	if (format.flag_ascii['-'])
	{
		write(1, &ch, 1);
		ft_print_width(format.width - 1);
	}
	else
	{
		ft_print_width(format.width - 1);
		write(1, &ch, 1);
	}
	if (!format.width)
		return (1);
	return (format.width);
}
