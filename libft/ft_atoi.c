/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:44:37 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/14 16:32:20 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	del_ws(const char **str)
{
	while (**str)
	{
		if ((9 <= **str && **str <= 13) || **str == 32)
			(*str)++;
		else
			break ;
	}
}

int	confirm_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '+')
		(*str)++;
	else if (**str == '-')
	{
		(*str)++;
		sign = -1;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			idx;
	int			sign;

	num = 0;
	idx = 0;
	del_ws(&str);
	sign = confirm_sign(&str);
	while (str[idx])
	{
		if ('0' <= str[idx] && str[idx] <= '9')
		{
			num *= 10;
			num += str[idx] - '0';
			idx++;
		}
		else
			break ;
	}
	return ((int)(sign * num));
}
