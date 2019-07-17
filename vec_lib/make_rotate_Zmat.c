/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rotate_Zmat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 07:10:44 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/17 07:53:05 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vec.h"

t_matrix	*make_rotate_Zmat(float fAngleRad)
{
	t_matrix	*m;

	m = NULL;
	m = init_to_0(m, 4, 4);
	m->m[0][0] = cosf(fAngleRad);
	m->m[0][1] = sinf(fAngleRad);
	m->m[1][0] = -sinf(fAngleRad);
	m->m[1][1] = cosf(fAngleRad);
	m->m[2][2] = 1;
	m->m[3][3] = 1;
	return (m);
}