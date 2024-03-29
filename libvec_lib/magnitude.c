/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:34:49 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/26 09:06:25 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libvec.h"

float		magnitude(t_point n, t_point o)
{
	float i;

	i = sqrt(pow((o.x - n.x), 2) + pow((o.y - n.y), 2) + pow((o.z - n.z), 2));
	return (i);
}
