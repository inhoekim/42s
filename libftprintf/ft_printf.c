/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:39:03 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/27 09:39:04 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "printft.h"

int	ft_printf(const char *s, ...)
{
	va_list		args;
	long long	print_cnt;

	if (s == NULL)
		return (-1);
	va_start(args, s);
	while (*s != '\0')     
	{
		if (*s == '%')
		{
			s++;
			if (!ft_init_format(&s, &args))
				return (-1);
			print_cnt += 
		}
		else
		{
			ft_putchar(*s);
			s++;
		}
	}
	if (args.)
	va_end(args);
	return (print_cnt);
}

/*	
	char flags_ch[5] = {'#', '+', '-', ' ', '0'};
	char precision_ch = '.';
	char conv_cr[9] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'};
	i = 0;
	int conv_i, flags_i, width, precision_i;
	precision_i = 0;
	while(s[i])
	{
		if(s[i] == '%')
		{
			if (is_in_flags(s[i], flags_ch, &flags_i))
			{
				i++;
			}
			if(is_in_width(s[i], width_ch, &width_i))
			{
				while(is_digit(s[i]))
				{
					// atoi_s.append(s[i])
					i++;
				}
				// width = atoi(atoi_s);
			}
			if(s[i] == precision_ch)
			{
				precision_i = 1;
				while(is_digit(s[i]))
				{
					// atoi_s.append(s[i])
					i++;
				}
				// minimum_of_digit = atoi(atoi_s);
			}
			i++;
			if(is_in_conversion(s[i], conversion_ch, &conversion_i))
			{
				// pass
			}
			else
				//error (print -1)
		}
		write(1, &s[i], 1);
		i++;
	}
}


int main()
{
	// size_t size = _INTSIZEOF(struct example.decimal); // 4
	// size_t struct_size = sizeof(struct example);
	ft_printf("%d", 2);

}
*/