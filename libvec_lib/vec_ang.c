/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvec_ang.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:56:21 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/16 11:05:44 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

float		libvec_ang(t_point *o, t_point *a, t_point *b)
{
	float i;

	i = dot_prod(a,b) / (magnitude(o, a) * magnitude(o, b));
	return (i);
}