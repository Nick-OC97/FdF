/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:29:29 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/26 09:30:20 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "../../libft/includes/libft.h"
# include <stdio.h>

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_point;

typedef struct	s_matrix
{
	double	m[4][4];
}				t_matrix;

float			dot_prod(t_point a, t_point b);
float			vec_ang(t_point o, t_point a, t_point b);
float			magnitude(t_point o, t_point n);
t_matrix		make_projec_matrix(float f_near, float f_far, float f_fov,
				float f_ar);
t_point			matrix_vecmultiply(t_point a, t_matrix b);
void			init_to_0(t_matrix *m, int x_size, int y_size);
t_point			vec_add(t_point a, t_point b);
t_point			vec_subtract(t_point a, t_point b);
t_point			scalar_vec_div(t_point a, float n);
t_point			scalar_vec_multiply(t_point a, float n);
t_point			cross_prod(t_point a, t_point b);
t_matrix		make_rotate_zmat(float f_angle_rad);
t_matrix		make_rotate_xmat(float f_angle_rad);
t_matrix		make_rotate_ymat(float f_angle_rad);
t_matrix		make_translate_matrix(float x, float y, float z);
t_matrix		matrix_multiply_matrix(t_matrix a, t_matrix b);
t_matrix		make_identity_matrix(void);
t_matrix		make_world_matrix(t_matrix zrot, t_matrix xrot,
				t_matrix transmat);
t_matrix		make_scale_matrix(float x, float y, float z);
t_point			vec_normalise(t_point a, t_point b);

#endif
