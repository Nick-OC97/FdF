/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_prod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:37:24 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/26 09:05:10 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

t_point		cross_prod(t_point a, t_point b)
{
	t_point		o;

	o.x = a.y * b.z - a.z * b.y;
	o.y = a.z * b.x - a.x * b.z;
	o.z = a.x * b.y - a.y * b.x;
	return (o);
}
