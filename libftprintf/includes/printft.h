/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:18:43 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/27 12:20:18 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFT.H
# define PRINTFT.H
# define FT_NULL 0
# define FT_FALSE 0
# define FT_TRUE 1
# include <stddef.h>

typedef struct	s_format{
	unsigned char	format_flag;
	unsigned char	conversion;
	long long		precision_exist;
	long long		width;
	long long		precision_width;
	long long		print_cnt;
}				t_format;
void	*ft_memset(void *b, int c, size_t len);
#endif
