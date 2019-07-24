/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:32:27 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/24 10:11:35 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"
#include <stdio.h>

void	draw_line(t_point p1, t_point p2, t_master master)
{
	float dx;
	float dy;
	float step;
	float i;

	dx = (p2.x - p1.x);
	dy = (p2.y - p1.y);
	if (fabsf(dx) >= fabsf(dy))
		step = fabsf(dx);
	else
		step = fabsf(dy);
	dx = dx / step;
	dy = dy / step;
	i = 1;
	while (i < step)
	{
		put_pxlto_img(&master.img, 0xFFFFFF, p1.x, p1.y);
		p1.x = p1.x + dx;
		p1.y = p1.y + dy;
		i++;
	}
	put_pxlto_img(&master.img, 0xFFFFFF, p1.x, p1.y);
}

void	draw_func(t_master master)
{
	int x;
	int j;

	x = 0;
	j = 1;
	while (x < (master.grid.num_tot))
	{
		if (j < master.grid.num_x)
			draw_line(master.lst[x], master.lst[x + 1], master);
		else
			j = 0;
		x++;
		j++;
	}
	x = 0;
	while (x < (master.grid.num_tot))
	{
		if (x < master.grid.num_tot - master.grid.num_x)
			draw_line(master.lst[x], master.lst[x + master.grid.num_x], master);
		x++;
	}
}
