/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:56:09 by inhkim            #+#    #+#             */
/*   Updated: 2023/09/17 20:29:32 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./libft/libft.h"
# include <signal.h>
# include <unistd.h>

typedef struct s_buff
{
	int		offset;
	char	buf;
}	t_buff;
int	check_pid(char *pid_str);
#endif

