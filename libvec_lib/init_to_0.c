/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_to_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 10:32:32 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/17 11:15:54 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

t_matrix	*init_to_0(t_matrix *m, int x_size, int y_size)
{
	int x;
	int y;

	y = 0;
	m = (t_matrix *)malloc(sizeof(t_matrix));
	while(y <= y_size)
	{
		x = 0;
		while (x <= x_size)
		{
			m->m[y][x] = 0;
			x++;
		}
		y++;
	}
	return (m);
}