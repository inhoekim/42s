/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limitsft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 03:34:54 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/21 03:50:52 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIMITSFT_H
# define LIMITSFT_H
# include "wordsizeft.h"
# if FT_WORDSIZE == 64
#  define FT_LONG_MAX 9223372036854775807L
# else
#  define FT_LONG_MAX 2147483647L
# endif
# define FT_INT_MAX 2147483647
#endif
