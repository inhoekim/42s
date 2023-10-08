/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 05:41:58 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/24 22:22:42 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head_node;

	if (lst == FT_NULL)
		return ;
	head_node = *lst;
	if (*lst == FT_NULL)
		*lst = new;
	else
	{
		while (FT_TRUE)
		{
			if ((*lst)->next == FT_NULL)
			{
				(*lst)->next = new;
				*lst = head_node;
				return ;
			}
			*lst = (*lst)->next;
		}	
	}
}
