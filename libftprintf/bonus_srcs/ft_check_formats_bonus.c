/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_formats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:36:14 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/29 05:36:53 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printft.h"

static int	check_conversion(t_format *format)
{
	if (format->conversion == 'c' && (format->flag_ascii['+'] || \
	format->flag_ascii[' '] || format->flag_ascii['#'] || \
	format->flag_ascii['0'] || (format->prec && format->prec_width)))
		return (0);
	if (format->conversion == 's' && (format->flag_ascii['+'] || \
	format->flag_ascii[' '] || format->flag_ascii['#'] \
	|| format->flag_ascii['0']))
		return (0);
	if (format->conversion == 'p' && (format->flag_ascii['+'] || \
	format->flag_ascii[' '] || format->flag_ascii['#'] || \
	format->flag_ascii['0'] || (format->prec && format->prec_width)))
		return (0);
	if ((format->conversion == 'd' || format->conversion == 'i') \
	&& format->flag_ascii['#'])
		return (0);
	if (format->conversion == 'u' && (format->flag_ascii['+'] \
	|| format->flag_ascii[' '] || format->flag_ascii['#']))
		return (0);
	if ((format->conversion == 'x' || format->conversion == 'X') \
	&& (format->flag_ascii['+'] || format->flag_ascii[' ']))
		return (0);
	return (1);
}

int	ft_check_formats(t_format_lst *lst)
{
	t_format	*format;

	lst = lst->next;
	while (lst)
	{
		format = lst->current;
		if (((format->flag_ascii['+'] && format->flag_ascii[' ']) \
			|| (format->flag_ascii['-'] && format->flag_ascii['0'])) \
			&& format->conversion != '%')
			return (0);
		if (format->width >= 2147483647 || format->prec_width >= 2147483647)
			return (0);
		if (!check_conversion(format))
			return (0);
		lst = lst->next;
	}
	return (1);
}
