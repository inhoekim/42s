#include "ft_printf.h"

void	ft_err(long long write_cnt, t_check_wdata *data)
{
	if (write_cnt < 0)
		data->is_minus = 1;
	else
		data->cnt += write_cnt;
}
