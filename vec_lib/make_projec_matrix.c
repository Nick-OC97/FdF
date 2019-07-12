/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_projec_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicholasoconnell <nicholasoconnell@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:04:50 by nicholasoco       #+#    #+#             */
/*   Updated: 2019/07/12 12:16:17 by nicholasoco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vec.h"

t_matrix	*make_proj_matrix(float fNear, float fFar, float fFov, float fAR)
{
	t_matrix	*proj;
	float		fFovRad;

	proj = (t_matrix *)malloc(sizeof(t_matrix));
	proj = 0;
	fFovRad = 1 / tanf(fFov * 0.5 / 180 * M_PI);
	proj->m[0][0] = fAR * fFovRad;
	proj->m[1][1] = fFovRad;
	proj->m[2][2] = fFar / fFar - fNear;
	proj->m[3][2] = (-fFar * fNear) / (fFar - fNear);
	proj->m[2][3] = 1;
	proj->m[3][3] = 0;
	return (proj);
}