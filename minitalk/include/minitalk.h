/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:56:09 by inhkim            #+#    #+#             */
/*   Updated: 2023/10/09 18:29:53 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define TIME_OUT 2000000000
# include "../libft/libft.h"
# include <signal.h>
# include <unistd.h>

typedef struct s_buff
{
	sig_atomic_t	offset;
	sig_atomic_t	buf;
	sig_atomic_t	curr_pid;
}	t_buff;
#endif
