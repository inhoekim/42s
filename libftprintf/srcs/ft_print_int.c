
#include "../includes/printft.h"

static int	get_int_len(long long n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	recur_set_str(char *str, long long num, int depth, int num_len)
{
	if (num / 10 == 0)
	{
		str[num_len - depth] = (num % 10) + '0';
		return ;
	}
	recur_set_str(str, num / 10, depth + 1, num_len);
	str[num_len - depth] = (num % 10) + '0';
}


static void	*int_to_alpha(long long num, char *num_str)
{
	int			is_minus;
	int			num_len;

	is_minus = FT_FALSE;
	if (num < 0)
	{
		num *= -1;
		is_minus = FT_TRUE;
	}
	num_len = get_int_len(num);
	if (is_minus)
		num_str[0] = '-';
	num_str[num_len + is_minus] = '\0';
	recur_set_str(num_str, num, 0, num_len + is_minus - 1);
}

long long	ft_print_int(t_format *format, long long num)
{
	long long	cnt;
	long long	str_len;
	char 		num_str[11];

	if (num < -FT_INT_MAX - 1 || num > FT_INT_MAX)
		return (0);
	cnt = 0;
	int_to_alpha(num, num_str);
	str_len = ft_strlen(num_str);
	if (format->prec)
		str_len = format->prec_width;
	if (format->flag_ascii['-'])
	{
		cnt += ft_putstr_fd(num_str, str_len, 1);
		cnt += ft_print_width(format->width - str_len);
	}
	else
	{
		cnt += ft_print_width(format->width - str_len);
		cnt += ft_putstr_fd(num_str, str_len, 1);
	}
	return (cnt);
}