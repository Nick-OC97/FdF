/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_to_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 10:32:32 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/19 16:58:45 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

void	init_to_0(t_matrix *m, int x_size, int y_size)
{
	int x;
	int y;

	y = 0;
	while(y < y_size)
	{
		x = 0;
		while (x < x_size)
		{
			m->m[x][y] = 0;
			x++;
		}
		y++;
	}
}