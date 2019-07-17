/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rotate_Ymat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 07:24:12 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/17 11:15:54 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

t_matrix	*make_rotate_Ymat(float fAngleRad)
{
	t_matrix	*m;

	m = NULL;
	m = init_to_0(m, 4, 4);
	m->m[0][0] = cosf(fAngleRad);
	m->m[0][2] = sinf(fAngleRad);
	m->m[2][0] = -sinf(fAngleRad);
	m->m[1][1] = 1;
	m->m[2][2] = cosf(fAngleRad);
	m->m[3][3] = 1;
	return (m);
}