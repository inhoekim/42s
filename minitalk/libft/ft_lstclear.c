/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 06:00:29 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/19 06:00:29 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_node;

	if (lst == FT_NULL)
		return ;
	while (*lst != FT_NULL)
	{
		temp_node = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(temp_node);
	}
}
