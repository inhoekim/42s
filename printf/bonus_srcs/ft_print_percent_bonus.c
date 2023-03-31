/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:47:03 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 10:47:06 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long long	ft_print_percent(void)
{
	long long	cnt;

	cnt = 0;
	cnt += write(1, "%", 1);
	return (cnt);
}
