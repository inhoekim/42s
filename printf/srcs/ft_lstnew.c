/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 04:16:15 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/19 04:16:16 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_format_lst	*ft_lstnew(t_format content)
{
	t_format_lst	*new_list;

	if (!content.complete)
		return (FT_NULL);
	new_list = (t_format_lst *)malloc(sizeof(t_format_lst));
	if (new_list == FT_NULL)
		return (FT_NULL);
	new_list->current = content;
	new_list->next = FT_NULL;
	return (new_list);
}
