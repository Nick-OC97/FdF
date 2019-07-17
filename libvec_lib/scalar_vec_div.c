/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_libvec_div.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:02:15 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/16 11:03:14 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

t_point		*scalar_libvec_div(t_point *a, float n)
{
	t_point		*o;

	o = (t_point *)malloc(sizeof(t_point));
	o->x = a->x / n;
	o->y = a->y / n;
	o->z = a->z / n;
	return (o);
}