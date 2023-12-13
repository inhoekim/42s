/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:37:15 by inhkim            #+#    #+#             */
/*   Updated: 2023/12/14 03:19:10 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define FALSE 0
# define TRUE 1

typedef struct s_triple	t_vector;
typedef struct s_triple	t_coord;

typedef struct s_triple
{
	float	x;
	float	y;
	float	z;
}	t_triple;
#endif
