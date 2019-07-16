/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_identity_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 12:32:55 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/16 12:35:42 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vec.h"

t_matrix	*make_identity_matrix(void)
{
	t_matrix	*i;

	i = (t_matrix *)malloc(sizeof(t_matrix));
	i->m[0][0] = 1;
	i->m[1][1] = 1;
	i->m[2][2] = 1;
	i->m[3][3] = 1;
	return (i);
}