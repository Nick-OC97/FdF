/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:07:22 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/26 09:21:37 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

t_point		vec_normalise(t_point a, t_point b)
{
	float l;

	l = magnitude(a, b);
	a.x = a.x / l;
	a.y = a.y / l;
	a.z = a.z / l;
	return (a);
}
