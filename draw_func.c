/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:32:27 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/23 10:03:08 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"
#include <stdio.h>

void	draw_line(t_point p1, t_point p2, t_mlx_acc acc)
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
	mlx_clear_window(acc.mlx_ptr, acc.win_ptr);
	while (i < step)
	{
		mlx_pixel_put(acc.mlx_ptr, acc.win_ptr, p1.x, p1.y, 0xFFFFFF);
		p1.x = p1.x + dx;
		p1.y = p1.y + dy;
		i++;
	}
	mlx_pixel_put(acc.mlx_ptr, acc.win_ptr, p1.x, p1.y, 0xFFFFFF);
}

void	draw_func(t_point *lst, t_grid_sizes grid, t_mlx_acc acc)
{
	int x;
	int j;

	x = 0;
	j = 1;
	while (x < (grid.num_tot))
	{
		if (j < grid.num_x)
			draw_line(lst[x], lst[x + 1], acc);
		else
			j = 0;
		x++;
		j++;
	}
	x = 0;
	while (x < (grid.num_tot))
	{
		if (x < grid.num_tot - grid.num_x)
			draw_line(lst[x], lst[x + grid.num_x], acc);
		x++;
	}
}
