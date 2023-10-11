/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:25:44 by inhkim            #+#    #+#             */
/*   Updated: 2023/10/11 14:25:49 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H
# define INT_MAX 2147483647

int				ft_strlen(char *str, char end);
int				chk_str(char *dst, char *src);
char			*ft_itoa(unsigned int n);
unsigned int	num_len(unsigned int n);
#endif
