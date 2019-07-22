/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:50:09 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/22 13:57:41 by no-conne         ###   ########.fr       */
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
	int				x_size;
	int				total_size;
	int				y_size;
	int				fd;
	char			*line;
	char			**inf;
	t_grid_sizes	grid;

	total_size = 0;
	y_size = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		x_size = 0;
		inf = ft_strsplit(line, ' ');
		while (inf[x_size])
		{
			total_size++;
			x_size++;
		}
		y_size++;
	}
	grid = ft_lstnew_fdf(x_size, y_size, total_size);
	return (grid);
}

t_point				*interpreter(const char *path, t_grid_sizes grid)
{
	int		fd;
	char	*line;
	char	**inf;
	int		x;
	int		y;
	t_point *data_s;
	t_point *data;

	y = 0;
	data = (t_point *)malloc(sizeof(t_point) * grid.num_tot);
	data_s = data;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		inf = ft_strsplit(line, ' ');
		while (x < grid.num_x)
		{
			data->x = x;
			data->y = y;
			data->z = ft_atoi(inf[x]);
			x++;
			data++;
		}
		y++;
	}
	return (data_s);
}
