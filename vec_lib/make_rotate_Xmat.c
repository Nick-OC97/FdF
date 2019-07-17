/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rotate_Xmat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 07:21:45 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/17 07:53:04 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vec.h"

t_matrix	*make_rotate_Xmat(float fAngleRad)
{
	t_matrix	*m;

	m = NULL;
	m = init_to_0(m, 4, 4);
	m->m[0][0] = 1;
	m->m[1][1] = cosf(fAngleRad);
	m->m[1][2] = sinf(fAngleRad);
	m->m[2][1] = -sinf(fAngleRad);
	m->m[2][2] = cosf(fAngleRad);
	m->m[3][3] = 1;
	return (m);
}