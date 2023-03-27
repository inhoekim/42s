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

#include <stdarg.h>
#include "printft.h"
/*	== %.format ==
	%[flags][width][precision]conversion
	flags: # + - ' ' 0
	width: field_width
	precision: .
	conversion: [cspdiuxX%]
	# + -  ' ' 0 field_width . [cspdiuxX%]   << 8개
*/
static unsigned char	g_flags[256];
static unsigned char	g_conversions[256];

t_format	*init_format(const char **s, va_list *args)
{
	t_format *format;

	format = create_format('\0', 0, 0, 0);
	if (format == FT_NULL)
		return (FT_NULL);
	while (**s != '\0')
	{
		if (g_conversions[(unsigned char)**s])
			return (format);
	}
	return (NULL);
}

static void	assign_gvlaue()
{
	ft_memset(g_flags, 0, 256);
	ft_memset(g_conversions, 0, 256);
	g_flags['+']++;
	g_flags['-']++;
	g_flags[' ']++;
	g_flags['0']++;
	g_flags['#']++;
	g_conversions['c']++;
	g_conversions['s']++;
	g_conversions['p']++;
	g_conversions['d']++;
	g_conversions['i']++;
	g_conversions['u']++;
	g_conversions['x']++;
	g_conversions['X']++;
	g_conversions['%']++;
}

static t_format	*create_format(unsigned char format_flag, int precision_exist, \
int width, int precision_width)
{
	t_format *format = (t_format *)malloc(sizeof(t_format));
	if (format == FT_NULL)
		return (FT_NULL);
	format->format_flag = format_flag;
	format->precision_exist = precision_exist;
	format->width = width;
	format->precision_width = precision_width;
	return (format);
}

int	print_format()
{

}