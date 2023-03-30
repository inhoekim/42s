#include <unistd.h>

long long	ft_print_zero(int width)
{
	long long	cnt;

	cnt = 0;
	while (width > 0)
	{
		cnt += write(1, "0", 1);
		width--;
	}
	return (cnt);
}
