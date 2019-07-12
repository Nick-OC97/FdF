/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicholasoconnell <nicholasoconnell@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:29:29 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/12 12:24:19 by nicholasoco      ###   ########.fr       */
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
	float		x;
	float		y;
	float		z;
}			t_point;

typedef struct s_matrix
{
	float	m[4][4];
}				t_matrix;

float		dot_prod(t_point *a, t_point *b);
float		vec_ang(t_point *o, t_point *a, t_point *b);
float		mag(t_point *o, t_point *n);
t_matrix	*make_projec_matrix(float fNear, float fFar, float fFov, float fAR);

#endif