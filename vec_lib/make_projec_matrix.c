/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_projec_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:04:50 by nicholasoco       #+#    #+#             */
/*   Updated: 2019/07/15 10:16:52 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vec.h"
#include <stdio.h>

t_matrix	*make_projec_matrix(double fNear, double fFar, double fFov, double fAR)
{
	t_matrix	*proj;
	double		fFovRad;
	int x;
	int y;

	y = 0;
	proj = (t_matrix *)malloc(sizeof(t_matrix));
	while(y <=3)
	{
		x = 0;
		while (x <= 3)
		{
			proj->m[y][x] = 0;
			x++;
		}
		y++;
	}
	fFovRad = 1 / tan(fFov * 0.5 / 180 * M_PI);
	printf("this is fFovRad: %f\n", fFovRad);
	proj->m[0][0] = fAR * fFovRad;
	proj->m[1][1] = fFovRad;
	proj->m[2][2] = fFar / fFar - fNear;
	proj->m[3][2] = (-fFar * fNear) / (fFar - fNear);
	proj->m[2][3] = 1;
	proj->m[3][3] = 0;
	return (proj);
}