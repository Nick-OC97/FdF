/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_translate_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 07:33:11 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/17 07:54:01 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vec.h"

t_matrix	*make_translate_matrix(float x, float y, float z)
{
	t_matrix	*m;

	m = NULL;
	m = init_to_0(m, 4, 4);
	m->m[0][0] = 1;
	m->m[1][1] = 1;
	m->m[2][2] = 1;
	m->m[3][3] = 1;
	m->m[3][0] = x;
	m->m[3][1] = y;
	m->m[3][2] = z;
	return (m);
}