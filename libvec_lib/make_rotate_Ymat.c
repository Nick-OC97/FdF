/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rotate_ymat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 07:24:12 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/26 09:12:43 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

t_matrix	make_rotate_ymat(float f_angle_rad)
{
	t_matrix	m;

	init_to_0(&m, 4, 4);
	m.m[0][0] = cosf(f_angle_rad);
	m.m[0][2] = sinf(f_angle_rad);
	m.m[2][0] = -sinf(f_angle_rad);
	m.m[1][1] = 1;
	m.m[2][2] = cosf(f_angle_rad);
	m.m[3][3] = 1;
	return (m);
}
