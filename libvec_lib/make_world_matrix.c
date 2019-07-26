/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_world_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 08:00:48 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/26 09:17:10 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

t_matrix	make_world_matrix(t_matrix zrot, t_matrix xrot, t_matrix transmat)
{
	t_matrix	m;

	m = make_identity_matrix();
	m = matrix_multiply_matrix(zrot, xrot);
	m = matrix_multiply_matrix(m, transmat);
	return (m);
}
