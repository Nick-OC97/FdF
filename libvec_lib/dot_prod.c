/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_prod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:25:27 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/22 07:41:49 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

float		dot_prod(t_point a, t_point b)
{
	float i;
	
	i = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (i); 
}