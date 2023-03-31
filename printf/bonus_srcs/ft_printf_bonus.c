/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:49:31 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 10:49:34 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf_bonus.h"

static t_format_lst	*make_format_lst(const char *s)
{
	t_format_lst	*format_lst;
	t_format_lst	*lst_head;

	format_lst = (t_format_lst *)malloc(sizeof(t_format_lst));
	if (format_lst == FT_NULL)
		return (FT_NULL);
	format_lst->current = FT_NULL;
	lst_head = format_lst;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			format_lst->next = ft_lstnew(ft_init_format(&s));
			if (format_lst->next == FT_NULL \
			|| format_lst->next->current == FT_NULL)
			{
				ft_lstclear(lst_head);
				return (FT_NULL);
			}
			format_lst = format_lst->next;
		}
		else
			s++;
	}
	return (lst_head);
}

static long long	start_print(const char *s, va_list *args, t_format_lst *lst)
{
	long long	print_cnt;

	lst = lst->next;
	print_cnt = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			print_cnt += ft_print_format(lst->current, args);
			s += lst->current->idx_len;
			lst = lst->next;
			continue ;
		}
		print_cnt += ft_putchar_fd(*s, 1);
		s++;
	}
	return (print_cnt);
}

int	ft_printf(const char *s, ...)
{
	va_list			args;
	long long		print_cnt;
	t_format_lst	*format_lst;

	if (s == FT_NULL)
		return (-1);
	format_lst = make_format_lst(s);
	if (format_lst == FT_NULL || !ft_check_formats(format_lst))
	{
		ft_lstclear(format_lst);
		return (-1);
	}
	va_start(args, s);
	print_cnt = 0;
	print_cnt += start_print(s, &args, format_lst);
	va_end(args);
	ft_lstclear(format_lst);
	return (print_cnt);
}
