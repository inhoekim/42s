#include <stdlib.h>
#include "../so_long.h"

static void	recur_set_str(char *str, unsigned long num, \
unsigned long depth, unsigned long num_len)
{
	if (num / 10 == 0)
	{
		str[num_len - depth] = (num % 10) + '0';
		return ;
	}
	recur_set_str(str, num / 10, depth + 1, num_len);
	str[num_len - depth] = (num % 10) + '0';
}

unsigned long	num_len(unsigned long n)
{
	unsigned long	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(unsigned long n)
{
	char			*num_alpha;
	unsigned long	num_len;

	num_len = num_len(n);
	num_alpha = (char *)malloc(sizeof(char) * (num_len + 1));
	if (num_alpha == FT_NULL)
		return (FT_NULL);
	num_alpha[num_len] = '\0';
	recur_set_str(num_alpha, n, 0, num_len - 1);
	return (num_alpha);
}