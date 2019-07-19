/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_libvec_multiply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 10:59:31 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/16 11:01:54 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

t_point		scalar_libvec_multiply(t_point a, float n)
{
	t_point		o;

	o.x = a.x * n;
	o.y = a.y * n;
	o.z = a.z * n;
	return (o);
}