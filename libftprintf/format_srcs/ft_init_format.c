/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:56:18 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/27 09:56:20 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/printft.h"
/*	=== format ===
	%[flags][width][precision]conversion
	flags: # + - ' ' 0
	width: field_width
	precision: .
	conversion: [cspdiuxX%]
*/
static unsigned char	g_conversions[256];
static unsigned char	g_flags[256];

static void	assign_gvalue(void)
{
	ft_memset(g_conversions, 0, 256);
	g_conversions['c']++;
	g_conversions['s']++;
	g_conversions['p']++;
	g_conversions['d']++;
	g_conversions['i']++;
	g_conversions['u']++;
	g_conversions['x']++;
	g_conversions['X']++;
	g_conversions['%']++;
	g_flags['#']++;
	g_flags['+']++;
	g_flags['-']++;
	g_flags[' ']++;
}

static t_format	*create_format(void)
{
	t_format	*format;

	format = (t_format *)malloc(sizeof(t_format));
	if (format == FT_NULL)
		return (FT_NULL);
	ft_memset(format->flag_ascii, 0, 256);
	format->conversion = 0;
	format->width = 0;
	format->prec_width = 0;
	format->prec = 0;
	format->idx_len = 1;
	return (format);
}

static int	make_format(const char ch, t_format *format)
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
		if (!g_flags[ch] || (g_flags[ch] && (format->width || format->prec)))
			return (0);
		format->flag_ascii[ch]++;
	}
	return (1);
}

t_format	*ft_init_format(const char **s)
{
	t_format	*format;

	assign_gvalue();
	format = create_format();
	if (format == FT_NULL)
		return (FT_NULL);
	(*s)++;
	while (**s != '\0')
	{
		format->idx_len++;
		if (g_conversions[(unsigned char)**s])
		{
			format->conversion = **s;
			(*s)++;
			return (format);
		}
		if (!make_format(**s, format))
			break ;
		(*s)++;
	}
	return (FT_NULL);
}
