/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:04:18 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/23 08:43:31 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"

void	translator(t_point *lst, t_mlx_acc acc, t_grid_sizes grid)
{
	int			x;
	t_matrix	translate;
	t_matrix	rot;
	t_matrix	rot2;

	x = 0;
	translate = make_translate_matrix(350, 400, 0);
	rot = make_rotate_Xmat(1);
	rot2 = make_rotate_Ymat(-0.75);
	while (x < (grid.num_tot))
	{
		lst[x] = scalar_vec_multiply(lst[x], 20);
		lst[x] = matrix_vecmultiply(lst[x], rot);
		lst[x] = matrix_vecmultiply(lst[x], rot2);
		lst[x] = matrix_vecmultiply(lst[x], translate);
		x++;
	}
	draw_func(lst, grid, acc);
}
