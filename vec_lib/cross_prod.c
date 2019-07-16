/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_prod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:37:24 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/16 11:44:57 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vec.h"

t_point		*cross_prod(t_point *a, t_point *b)
{
	t_point		*o;

	x = (t_point *)malloc(sizeof(t_point));
	o->x = a->y * a->z - a->z * a->y;
	o->y = a->z * a->x - a->x * a->z;
	o->z = a->x * a->y - a->y * a->x;
	return (o);
}