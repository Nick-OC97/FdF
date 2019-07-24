/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:04:18 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/24 16:09:22 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"

void	translator(t_master *master)
{
	int			x;
	t_matrix	translate;
	t_matrix	rot;
	t_matrix	rot2;
	t_matrix	scale;
	t_matrix	mat;

	x = 0;
	translate = make_translate_matrix(master->trans_x, master->trans_y, master->trans_z);
	rot = make_rotate_Xmat(master->xa);
	rot2 = make_rotate_Ymat(master->ya);
	scale = make_scale_matrix(master->xt, master->yt, master->zt);
	mat = matrix_multiply_matrix(rot, rot2);
	mat = matrix_multiply_matrix(mat, scale);
	mat = matrix_multiply_matrix(mat, translate);
	while (x < (master->grid.num_tot))
	{
		master->screen_coords[x] = matrix_vecmultiply(master->original_coords[x], mat);
		x++;
	}
	draw_func(master);
}
