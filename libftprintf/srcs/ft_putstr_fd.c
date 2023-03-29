
#include <unistd.h>

 long long	ft_putstr_fd(char *str, long long len, int fd)
{
	long long	cnt;
	int			idx;

	cnt = 0;
	idx = 0;
	while (str[idx] && len > idx)
	{
		cnt += write(fd, &str[idx], 1);
		idx++;
	}
	return (cnt);
}