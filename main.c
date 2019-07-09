/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:07:25 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/09 13:37:46 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_grid_sizes		*ft_lstnew_fdf(int x_size, int y_size, int total_size)// puts column, row and total size in a struct
{
	t_grid_sizes	*grid;
	if (!(grid = (t_grid_sizes *)malloc(sizeof(t_grid_sizes))))
		return (NULL);
	grid->num_x = x_size;
	grid->num_y = y_size;
	grid->num_tot = total_size;
	return(grid);
}

t_grid_sizes		*get_sizes(void) //counts column, row and total size 
{
	int x_size;
	int total_size;
	int y_size;
	int fd;
	char *line;
	char **inf;
	t_grid_sizes *grid;

	x_size = 0;
	fd = open("./test_maps/42.fdf", O_RDONLY);
	while(get_next_line(fd, &line) > 0)
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

t_point *interpreter(const char* path, t_grid_sizes *grid) //turns string of characters into arry of points
{
	int fd;
	char *line;
	char **inf;
	int x;
	int y;
	t_point *data_s;
	t_point *data;

	y = 0;
	data = (t_point *)malloc(sizeof(t_point) * grid->num_tot);
	data_s = data;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		inf = ft_strsplit(line, ' ');
		while (x < grid->num_x)
		{
			data->x = x;
			data->y = y;
			data-> z= ft_atoi(inf[x]);
			x++;
			data++;
		}
		y++;
	}
	return (data_s);
}

int	my_key_funct(int keycode, void *param) //stopping loop with esc function
{
	ft_putstr("Key event: ");
	ft_putnbr(keycode);
	if (keycode == 53)
		exit (0);
	return (1);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int x;
	int y;
	t_mlx_acc	acc;
	t_point		*lst;
	t_grid_sizes	*grid;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "NICK");
	acc.mlx_ptr = mlx_ptr;
	acc.win_ptr = win_ptr;
	grid = get_sizes();
	lst = interpreter("./test_maps/42.fdf", grid);
	mlx_key_hook(win_ptr, my_key_funct, &acc);
	mlx_loop(mlx_ptr);
	return (0);
}
