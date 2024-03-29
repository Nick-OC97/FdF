/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ang.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:56:21 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/26 09:21:22 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

float		vec_ang(t_point o, t_point a, t_point b)
{
	float i;

	i = dot_prod(a, b) / (magnitude(o, a) * magnitude(o, b));
	return (i);
}
