/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_projec_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:04:50 by nicholasoco       #+#    #+#             */
/*   Updated: 2019/07/19 16:39:29 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"
#include <stdio.h>

t_matrix	make_projec_matrix(float fNear, float fFar, float fFov, float fAR)
{
	t_matrix	proj;
	float		fFovRad;


	init_to_0(&proj, 4, 4);
	fFovRad = 1 / tan((fFov * 0.5) / 180 * M_PI);
	proj.m[0][0] = fAR * fFovRad;
	proj.m[1][1] = fFovRad;
	proj.m[2][2] = fFar / fFar - fNear;
	proj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
	proj.m[2][3] = 1;
	proj.m[3][3] = 0;
	return (proj);
}