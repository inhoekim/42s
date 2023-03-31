/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:48:01 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/31 10:48:03 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdlib.h>

void	ft_lstclear(t_format_lst *lst)
{
	t_format_lst	*del_target;

	while (lst != FT_NULL)
	{
		del_target = lst;
		lst = lst->next;
		free(del_target->current);
		free(del_target);
	}
}
