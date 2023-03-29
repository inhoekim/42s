/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:18:43 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/27 12:20:18 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFT_H
# define PRINTFT_H
# define FT_NULL 0
# define FT_FALSE 0
# define FT_TRUE 1
# include <stddef.h>

typedef struct s_format
{
	unsigned char	flag_ascii[256];
	char			conversion;
	long long		width;
	long long		prec_width;
	long long		print_cnt;
	long long		idx_len;
	int				prec;
}t_format;
typedef struct s_format_lst
{
	struct s_format_lst	*next;
	t_format			*current;
}t_format_lst;
int				ft_check_formats(t_format_lst *lst);
t_format		*ft_init_format(const char **s);
long long		ft_print_format(t_format *format, va_list *args);
int				ft_isdigit(int c);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlen(const char *s);
long long		ft_print_width(int width);
long long		ft_print_str(t_format *format, char *str);
long long		ft_print_char(t_format *format, char ch);
long long		ft_print_addr(t_format *format, void *p);
int				ft_printf(const char *s, ...);
int				ft_putchar_fd(char c,int fd);
t_format_lst	*ft_lstnew(void *content);
#endif