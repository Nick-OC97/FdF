/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_projec_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:04:50 by nicholasoco       #+#    #+#             */
/*   Updated: 2019/07/26 09:08:59 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"
#include <stdio.h>

t_matrix	make_projec_matrix(float f_near, float f_far, float f_fov,
float f_ar)
{
	t_matrix	proj;
	float		f_fov_rad;

	init_to_0(&proj, 4, 4);
	f_fov_rad = 1 / tan((f_fov * 0.5) / 180 * M_PI);
	proj.m[0][0] = f_ar * f_fov_rad;
	proj.m[1][1] = f_fov_rad;
	proj.m[2][2] = f_far / f_far - f_near;
	proj.m[3][2] = (-f_far * f_near) / (f_far - f_near);
	proj.m[2][3] = 1;
	proj.m[3][3] = 0;
	return (proj);
}
