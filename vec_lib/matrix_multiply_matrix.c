/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 07:39:33 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/17 07:53:06 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vec.h"

t_matrix	*matrix_multiply_matrix(t_matrix *a, t_matrix *b)
{
	t_matrix	*m;
	int i;
	int j;

	i = 0;
	j = 0;
	m = NULL;
	m = init_to_0(m, 4, 4);
	while (i < 4)
	{
		j = 0;
		while(j < 4)
		{
			m->m[j][i] = a->m[j][0] * b->m[0][i] + a->m[j][1] * b->m[1][i] + a->m[j][2] * b->m[2][i] + a->m[j][3] * b->m[3][i];
			j++;
		}
		i++;
	}
	return (m);
}