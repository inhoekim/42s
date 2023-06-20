/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_format_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:46:19 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 10:46:43 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_bonus.h"
/*	=== format ===
	%[flags][width][precision]conversion
	flags: # + - ' ' 0
	width: field_width
	precision: .
	conversion: [cspdiuxX%]
*/
static void	assign_cfvalue(unsigned char *conversions, unsigned char *flags)
{
	ft_memset(conversions, 0, 256);
	ft_memset(flags, 0, 256);
	conversions['c']++;
	conversions['s']++;
	conversions['p']++;
	conversions['d']++;
	conversions['i']++;
	conversions['u']++;
	conversions['x']++;
	conversions['X']++;
	conversions['%']++;
	flags['#']++;
	flags['+']++;
	flags['-']++;
	flags[' ']++;
}

static void	create_format(t_format *format)
{
	ft_memset(format->flag_ascii, 0, 256);
	format->conversion = 0;
	format->width = 0;
	format->prec_width = 0;
	format->prec = 0;
	format->idx_len = 1;
	format->complete = 0;
}

static int	make_format(const unsigned char ch, \
t_format *format, unsigned char *flags)
{
	if (ft_isdigit(ch))
	{
		if (ch == '0' && !format->width && !format->prec)
			format->flag_ascii['0']++;
		if (!format->prec)
			format->width = (format->width * 10) + (ch - '0');
		else
			format->prec_width = (format->prec_width * 10) + (ch - '0');
	}
	else if (ch == '.')
	{
		if (format->prec != 0)
			return (0);
		else
			format->prec = 1;
	}
	else
	{
		if (!flags[(int)ch] || \
		(flags[(int)ch] && (format->width || format->prec)))
			return (0);
		format->flag_ascii[(int)ch]++;
	}
	return (1);
}

t_format	ft_init_format(const char **s)
{
	t_format		format;
	unsigned char	conversions[256];
	unsigned char	flags[256];

	assign_cfvalue(conversions, flags);
	create_format(&format);
	(*s)++;
	while (**s != '\0')
	{
		format.idx_len++;
		if (conversions[(unsigned char)**s])
		{
			format.complete = 1;
			format.conversion = **s;
			(*s)++;
			return (format);
		}
		if (!make_format(**s, &format, flags))
			break ;
		(*s)++;
	}
	return (format);
}
