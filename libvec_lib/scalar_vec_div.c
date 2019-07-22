/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_vec_div.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:02:15 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/22 07:39:46 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

t_point		scalar_vec_div(t_point a, float n)
{
	t_point		o;

	o.x = a.x / n;
	o.y = a.y / n;
	o.z = a.z / n;
	return (o);
}