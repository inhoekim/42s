/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 06:07:44 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/19 06:07:44 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_lst(t_list *head, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp_node;

	current = head;
	while (current != FT_NULL)
	{
		temp_node = current;
		del(current->content);
		current = current->next;
		free(temp_node);
	}
}

static t_list	*make_head(t_list *lst, void *(*f)(void *))
{
	t_list	*head;

	head = FT_NULL;
	if (lst != FT_NULL)
	{
		head = (t_list *)malloc(sizeof(t_list));
		if (head == FT_NULL)
			return (FT_NULL);
		head->content = f(lst->content);
		head->next = FT_NULL;
	}
	return (head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*before;
	t_list	*current;

	head = make_head(lst, f);
	if (head == FT_NULL)
		return (FT_NULL);
	before = head;
	lst = lst->next;
	while (lst != FT_NULL)
	{
		current = (t_list *)malloc(sizeof(t_list));
		if (current == FT_NULL)
		{
			free_lst(head, del);
			return (FT_NULL);
		}
		current->content = f(lst->content);
		current->next = FT_NULL;
		before->next = current;
		before = current;
		lst = lst->next;
	}
	return (head);
}
