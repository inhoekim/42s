/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordsizeft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 03:31:25 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/21 03:50:20 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORDSIZEFT_H
# define WORDSIZEFT_H
# ifdef __x86_64__
#  define FT_WORDSIZE 64
# else
#  define FT_WORDSIZE 32
# endif
#endif
