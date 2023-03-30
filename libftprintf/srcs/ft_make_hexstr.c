
#include "../includes/printft.h"

static void	*reverse_str(char *addr_str, size_t right_idx)
{
	size_t	left_idx;
	int		temp_num;

	left_idx = 0;
	while (left_idx < right_idx)
	{
		temp_num = addr_str[left_idx];
		addr_str[left_idx] = addr_str[right_idx];
		addr_str[right_idx] = temp_num;
		left_idx++;
		right_idx--;
	}
}

void    ft_make_hexstr(size_t addr, char addr_str[], int is_addr)
{
	const char	*hex_set = "0123456789abcdef";
	size_t		idx;

	addr_str[0] = '\0';
	idx = 1;
	while (addr)
	{
		addr_str[idx] = hex_set[addr % 16];
		addr /= 16;
		idx++;
	}
	if (is_addr)
	{
		addr_str[idx] = 'x';
		addr_str[++idx] = '0';
	}
	reverse_str(addr_str, idx);
}