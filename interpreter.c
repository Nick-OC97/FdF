/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:50:09 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/23 10:09:01 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"

t_grid_sizes		ft_lstnew_fdf(int x_size, int y_size, int total_size)
{
	t_grid_sizes	grid;

	grid.num_x = x_size;
	grid.num_y = y_size;
	grid.num_tot = total_size;
	return (grid);
}

t_grid_sizes		get_sizes(char *path)
{
	t_info			info;
	t_grid_sizes	grid;

	info.total_size = 0;
	info.y_size = 0;
	info.fd = open(path, O_RDONLY);
	while (get_next_line(info.fd, &info.line) > 0)
	{
		info.x_size = 0;
		info.inf = ft_strsplit(info.line, ' ');
		while (info.inf[info.x_size])
		{
			info.total_size++;
			info.x_size++;
		}
		free(info.inf);						//this
		info.y_size++;
	}
	grid = ft_lstnew_fdf(info.x_size, info.y_size, info.total_size);
	return (grid);
}

t_point				*interpreter(const char *path, t_grid_sizes grid)
{
	t_info	info;
	t_point *data_s;
	t_point *data;

	info.y_size = 0;
	data = (t_point *)malloc(sizeof(t_point) * grid.num_tot);
	data_s = data;
	info.fd = open(path, O_RDONLY);
	while (get_next_line(info.fd, &info.line) > 0)
	{
		info.x_size = 0;
		info.inf = ft_strsplit(info.line, ' ');
		while (info.x_size < grid.num_x)
		{
			data->x = info.x_size;
			data->y = info.y_size;
			data->z = ft_atoi(info.inf[info.x_size]);
			info.x_size++;
			data++;
		}
		free(info.inf);						//this
		info.y_size++;
	}
	return (data_s);
}
