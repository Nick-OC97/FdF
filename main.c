/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:07:25 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/15 10:41:27 by no-conne         ###   ########.fr       */
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

void	draw_line(int x1, int y1, int x2, int y2, t_mlx_acc acc)
{
	int dx;
	int dy;
	int step;
	int i;

	x1 = x1 * 20;
	y1 = y1 * 20;
	x2 = x2 * 20;
	y2 = y2 * 20;
	dx = (x2 - x1);
	dy = (y2 - y1);
	if (abs(dx) >= abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	dx = dx / step;
	dy = dy / step;
	i = 1;
	while (i < step)
	{
		mlx_pixel_put(acc.mlx_ptr, acc.win_ptr, x1, y1, 0xFFFFFF);
		x1 = x1 + dx;
		y1 = y1 + dy;
		i++;
	}
	mlx_pixel_put(acc.mlx_ptr, acc.win_ptr, x1, y1, 0xFFFFFF);
	
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int x;
	int y;
	t_mlx_acc	acc;
	t_point		*lst;
	t_point		*lst2;
	t_point		*lst_start;
	t_grid_sizes	*grid;
	t_matrix		*project;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "NICK");
	acc.mlx_ptr = mlx_ptr;
	acc.win_ptr = win_ptr;
	grid = get_sizes();
	lst = interpreter("./test_maps/42.fdf", grid);
	project = make_projec_matrix(0.1, 1000, 100, (500/500));			//testing projection matrix
	x = 0;
	y = 0;
	while (y <= 3)
	{
		x = 0;
		while (x <= 3)
		{
			ft_putnbr(project->m[x][y]);
			ft_putchar('\n');
			x++;
		}
		y++;
	}
	ft_putchar('\n');
	matrix_vecmultiply(lst, project);
	x = 0;
	lst2 = lst;
	lst_start = lst;
	lst2++;
	/* while (x < grid->num_tot)									testing the grid points
	{
		ft_putnbr(lst->x);
		ft_putnbr(lst->y);
		ft_putchar('\n');
		mlx_pixel_put(acc.mlx_ptr, acc.win_ptr, (lst->x) * 20, (lst->y) * 20, 0xFFFFFF);
		lst++;
		x++;
	}*/
	ft_putnbr(grid->num_x);
	ft_putnbr(grid->num_y);
	int count = 0;
	while (x < (grid->num_tot))										//testing drawing a flat grid x lines
	{
		if (lst->x == grid->num_x - 1 && lst->y == grid->num_y - 1)
			break;
		//ft_putnbr(lst->x);
		//ft_putnbr(lst->y);
		//ft_putchar('\n');
		draw_line(lst->x, lst->y, lst2->x, lst2->y, acc);
		x++;
		lst++;
		lst2++;
		count++;
	}
	lst = lst_start;
	lst2 = lst + grid->num_x;
	x = 0;
	while (x < (grid->num_tot))										//testing drawing a flat grid y lines
	{
		if (lst->x == 0 && lst->y == grid->num_y - 1)
			break;
		//ft_putnbr(lst->x);
		//ft_putnbr(lst->y);
		//ft_putchar('\n');
		draw_line(lst->x, lst->y, lst2->x, lst2->y, acc);
		x++;
		lst++;
		lst2++;
		count++;
	}
	ft_putnbr(count);
	mlx_key_hook(win_ptr, my_key_funct, &acc);
	mlx_loop(mlx_ptr);
	return (0);
}
