/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 05:33:49 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/19 05:33:51 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	node_cnt;

	node_cnt = 0;
	while (lst != FT_NULL)
	{
		node_cnt++;
		lst = lst->next;
	}
	return (node_cnt);
}
