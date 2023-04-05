/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:39:03 by inhkim            #+#    #+#             */
/*   Updated: 2023/04/05 20:29:42 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"

static t_format_lst	*make_lst_head(void)
{
	t_format_lst	*head;

	head = (t_format_lst *)malloc(sizeof(t_format_lst));
	if (head == FT_NULL)
		return (FT_NULL);
	head->next = FT_NULL;
	return (head);
}

static t_format_lst	*make_format_lst(const char *s)
{
	t_format_lst	*format_lst;
	t_format_lst	*lst_head;

	format_lst = make_lst_head();
	if (format_lst == FT_NULL)
		return (FT_NULL);
	lst_head = format_lst;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			format_lst->next = ft_lstnew(ft_init_format(&s));
			if (format_lst->next == FT_NULL)
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
	long long	temp;

	print_cnt = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			temp = ft_print_format(lst->current, args);
			if (temp < 0 || temp >= FT_INT_MAX)
				return (-1);
			print_cnt += temp;
			s += lst->current.idx_len;
			lst = lst->next;
			continue ;
		}
		temp = ft_putchar_fd(*s, 1);
		if (temp < 0)
			return (-1);
		print_cnt += temp;
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
	if (format_lst == FT_NULL || !ft_check_formats(format_lst->next))
	{
		ft_lstclear(format_lst);
		return (-1);
	}
	va_start(args, s);
	print_cnt = start_print(s, &args, format_lst->next);
	va_end(args);
	ft_lstclear(format_lst);
	if (print_cnt >= FT_INT_MAX)
		print_cnt = -1;
	return (print_cnt);
}
