/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:44:03 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 10:44:29 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FT_NULL 0
# define FT_FALSE 0
# define FT_TRUE 1
# define FT_INT_MAX 2147483647
# include <stddef.h>
# include <stdarg.h>

typedef struct s_format
{
	unsigned char	flag_ascii[256];
	char			conversion;
	long long		width;
	long long		prec_width;
	long long		idx_len;
	int				prec;
	int				complete;
}t_format;
typedef struct s_format_lst
{
	struct s_format_lst	*next;
	t_format			current;
}t_format_lst;
typedef struct s_len_data
{
	long long	str_len;
	long long	actual_len;
	int			is_minus;
}t_len_data;
int				ft_check_formats(t_format_lst *lst);
t_format		ft_init_format(const char **s);
long long		ft_print_format(t_format format, va_list *args);
int				ft_isdigit(unsigned char c);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlen(const char *s);
int				ft_intlen(long long n);
void			ft_itoa(long long num, char *num_str);
void			ft_make_hexstr(size_t addr, \
char *addr_str, int is_addr, int lower_case);
long long		ft_print_width(int width);
long long		ft_print_zero(int width);
long long		ft_print_str(t_format format, char *str);
long long		ft_print_char(t_format format, char ch);
long long		ft_print_addr(t_format format, long long p);
long long		ft_print_int(t_format format, int num);
long long		ft_print_uint(t_format format, unsigned int num);
long long		ft_print_percent(t_format format);
long long		ft_print_hex(t_format format, \
unsigned int num, int lower_case);
int				ft_printf(const char *s, ...);
int				ft_putchar_fd(char c, int fd);
long long		ft_putstr_fd(char *str, long long len, int fd);
t_format_lst	*ft_lstnew(t_format content);
void			ft_lstclear(t_format_lst *lst);
int				ft_err(long long write_cnt, long long *cnt);
#endif
