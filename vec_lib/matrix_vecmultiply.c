/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vecmultiply.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:55:26 by nicholasoco       #+#    #+#             */
/*   Updated: 2019/07/16 11:22:29 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vec.h"

void	matrix_vecmultiply(t_point *a, t_matrix *b)
{
	float		w;
	t_point		*o;

	o = (t_point *)malloc(sizeof(t_point));
	o->x = a->x * b->m[0][0] + a->y * b->m[1][0] + a->z * b->m[2][0] + b->m[3][0];
	o->y = a->x * b->m[0][1] + a->y * b->m[1][1] + a->z * b->m[2][1] + b->m[3][1];
	o->z = a->x * b->m[0][2] + a->y * b->m[1][2] + a->z * b->m[2][2] + b->m[3][2];
	w = a->x * b->m[0][3] + a->y * b->m[1][3] + a->z * b->m[2][3] + b->m[3][3];

	a->x = o->x;
	a->y = o->y;
	a->z = o->z;
	//free(o);
}