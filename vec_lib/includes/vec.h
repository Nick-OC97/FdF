/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:29:29 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/10 12:19:05 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}			t_point;

float		dot_prod(t_point *a, t_point *b);
float		vec_ang(t_point *o, t_point *a, t_point *b);
float		mag(t_point *o, t_point *n);

#endif