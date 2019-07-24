/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:04:18 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/24 07:39:18 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"

void	translator(t_master master)
{
	int			x;
	t_matrix	translate;
	t_matrix	rot;
	t_matrix	rot2;

	x = 0;
	translate = make_translate_matrix(350, 400, 0);
	rot = make_rotate_Xmat(1);
	rot2 = make_rotate_Ymat(-0.75);
	while (x < (master.grid.num_tot))
	{
		master.lst[x] = scalar_vec_multiply(master.lst[x], 20);
		master.lst[x] = matrix_vecmultiply(master.lst[x], rot);
		master.lst[x] = matrix_vecmultiply(master.lst[x], rot2);
		master.lst[x] = matrix_vecmultiply(master.lst[x], translate);
		x++;
	}
	draw_func(master);
}
