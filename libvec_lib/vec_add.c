/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 10:46:53 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/16 10:52:29 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

t_point		*libvec_add(t_point *a, t_point *b)
{
	t_point		*o;

	o = (t_point *)malloc(sizeof(t_point));
	o->x = a->x + b->x;
	o->y = a->y + b->y;
	o->z = a->z + b->z;
	return (o);
}