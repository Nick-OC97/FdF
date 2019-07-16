/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_subtract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 10:56:33 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/16 10:57:28 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vec.h"

t_point		*vec_subtract(t_point *a, t_point *b)
{
	t_point		*o;

	o = (t_point *)malloc(sizeof(t_point));
	o->x = b->x - a->x;
	o->y = b->y - a->y;
	o->z = b->z - a->z;
	return (o);
}