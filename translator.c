/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:04:18 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/26 09:13:54 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"

void	translator2(t_master *master, t_matrix mat)
{
	int x;

	x = 0;
	while (x < (master->grid.num_tot))
	{
		master->s_cords[x] = matrix_vecmultiply(master->o_cords[x], mat);
		x++;
	}
	draw_func(master);
}

void	translator(t_master *master)
{
	t_matrix	translate;
	t_matrix	rot;
	t_matrix	rot2;
	t_matrix	scale;
	t_matrix	mat;

	translate = make_translate_matrix(master->trans_x, master->trans_y,
	master->trans_z);
	rot = make_rotate_xmat(master->xa);
	rot2 = make_rotate_ymat(master->ya);
	scale = make_scale_matrix(master->xt, master->yt, master->zt);
	mat = matrix_multiply_matrix(rot, rot2);
	mat = matrix_multiply_matrix(mat, scale);
	mat = matrix_multiply_matrix(mat, translate);
	translator2(master, mat);
}
