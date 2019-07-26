/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:50:09 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/26 11:36:20 by no-conne         ###   ########.fr       */
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
			free(info.inf[info.x_size]);
			info.total_size++;
			info.x_size++;
		}
		free(info.inf);
		free(info.line);
		info.y_size++;
	}
	grid = ft_lstnew_fdf(info.x_size, info.y_size, info.total_size);
	return (grid);
}

void				m_func(t_master *master)
{
	master->o_cords = (t_point *)malloc(sizeof(t_point) * master->grid.num_tot);
	master->s_cords = (t_point *)malloc(sizeof(t_point) * master->grid.num_tot);
}

void				free_func(t_info info)
{
	free(info.inf);
	free(info.line);
}

void				interpreter(const char *path, t_master *master)
{
	t_info	info;

	info.total_size = 0;
	info.y_size = 0;
	m_func(master);
	info.fd = open(path, O_RDONLY);
	while (get_next_line(info.fd, &info.line) > 0)
	{
		info.x_size = 0;
		info.inf = ft_strsplit(info.line, ' ');
		checker(master, info);
		while (info.x_size < master->grid.num_x)
		{
			master->o_cords[info.total_size].x = info.x_size -
			(master->grid.num_x - 1) * 0.5;
			master->o_cords[info.total_size].y = info.y_size -
			(master->grid.num_y - 1) * 0.5;
			master->o_cords[info.total_size].z = ft_atoi(info.inf[info.x_size]);
			free(info.inf[info.x_size]);
			info.x_size++;
			info.total_size++;
		}
		free_func(info);
		info.y_size++;
	}
}
