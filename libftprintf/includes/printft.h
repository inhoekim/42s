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

#ifndef PRINTFT_H
# define PRINTFT_H
# define FT_NULL 0
# define FT_FALSE 0
# define FT_TRUE 1
# include <stddef.h>

typedef struct	s_format{
	unsigned char	flag_ascii[256];
	char			conversion;
	long long		width;
	long long		prec_width;
	long long		print_cnt;
	int				prec;
}				t_format;
typedef struct	s_format_lst{
	struct s_format_lst	*next;
	t_format			*current;
}				t_format_lst;
void		*ft_memset(void *, int, size_t);
int			ft_isdigit(int);
t_format	*ft_init_format(const char **);
#endif