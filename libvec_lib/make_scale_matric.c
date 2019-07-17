/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_scale_matric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:08:20 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/17 11:15:54 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

t_matrix	*make_scale_matrix(float x, float y, float z)
{
	t_matrix	*m;

	m = NULL;
	m = init_to_0(m, 4, 4);
	m->m[0][0] = x;
	m->m[1][1] = y;
	m->m[2][2] = z;
	m->m[3][3] = 1;
	return (m);
}