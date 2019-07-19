/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:07:25 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/19 17:22:26 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"
#include <stdio.h>

t_grid_sizes		ft_lstnew_fdf(int x_size, int y_size, int total_size)// puts column, row and total size in a struct
{
	t_grid_sizes	grid;
	grid.num_x = x_size;
	grid.num_y = y_size;
	grid.num_tot = total_size;
	return(grid);
}

t_grid_sizes		get_sizes(char *path) //counts column, row and total size 
{
	int x_size;
	int total_size;
	int y_size;
	int fd;
	char *line;
	char **inf;
	t_grid_sizes grid;

	x_size = 0;
	total_size = 0;
	y_size = 0;
	fd = open(path, O_RDONLY);
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

t_point *interpreter(const char* path, t_grid_sizes grid) //turns string of characters into arry of points
{
	int fd;
	char *line;
	char **inf;
	int x;
	int y;
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
	t_mlx_acc	*acc;

	acc = param;
	ft_putstr("Key event: ");
	ft_putnbr(keycode);
	if (keycode == 53)
		exit (0);
	return (1);
}

void	draw_line(float x1, float y1, float x2, float y2, t_mlx_acc acc)
{
	float dx;
	float dy;
	float step;
	float i;

	x1 = x1 * 20;
	y1 = y1 * 20;
	x2 = x2 * 20;
	y2 = y2 * 20;
	dx = (x2 - x1);
	dy = (y2 - y1);
	if (fabsf(dx) >= fabsf(dy))
		step = fabsf(dx);
	else
		step = fabsf(dy);
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

/*int		pepe(int button, int x, int y, t_mlx_acc acc)
{
	(void)button;
	t_point		*a;
	t_point		*b;
	a->x = 970;
	a->y = 530;
	b->x = x;
	b->y = y;
	draw_line(a->x, a->y, b->x, b->y, acc);
	return (0);
}*/

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("too many arguments");
		return (0);
	}
	void	*mlx_ptr;
	void	*win_ptr;
	int x;
	t_mlx_acc	acc;
	t_point		*lst;
	t_point		*lst2;
	t_point		*lst_start;
	t_grid_sizes	grid;
	t_matrix	translate,rot,rot2;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 600, 600, "NICK");
	acc.mlx_ptr = mlx_ptr;
	acc.win_ptr = win_ptr;
	grid = get_sizes(argv[1]);
	lst = interpreter(argv[1], grid);
	x = 0;
	lst2 = lst;
	lst_start = lst;
	lst2++;
	translate = make_translate_matrix(300,300,0);
	rot = make_rotate_Xmat(1);
	rot2 = make_rotate_Ymat(1);
	while (x < (grid.num_tot))									//moving grid
	{
		lst[x] = scalar_libvec_multiply(lst[x], 20);
		lst[x] = matrix_libvecmultiply(lst[x], rot);
		lst[x] = matrix_libvecmultiply(lst[x], rot2);
		lst[x] = matrix_libvecmultiply(lst[x], translate);
		ft_putnbr(lst[x].x);
		ft_putchar('\n');
		mlx_pixel_put(acc.mlx_ptr, acc.win_ptr, lst[x].x, lst[x].y, 0xffffff);
		x++;
	}
	/* lst = lst_start;
	x = 0;
 	while (x < (grid.num_tot))										//testing drawing a flat grid x lines
	{
		if (lst->x == grid.num_x - 1 && lst->y == grid.num_y - 1)
			break;
		if (lst->x == grid.num_x - 1)
		{
			lst++;
			lst2++;
		}
		ft_putnbr(lst->x);
		ft_putchar('\n');
		ft_putnbr(lst->y);
		ft_putchar('\n'); 
		draw_line(lst->x, lst->y, lst2->x, lst2->y, acc);
		x++;
		lst++;
		lst2++;
	}
	lst = lst_start;
	lst2 = lst + grid.num_x;
	x = 0;
	while (x < (grid.num_tot))										//testing drawing a flat grid y lines
	{
		if (lst->x == 0 && lst->y == grid.num_y - 1)
			break;
		draw_line(lst->x, lst->y, lst2->x, lst2->y, acc);
		x++;
		lst++;
		lst2++;
	} */
	mlx_key_hook(win_ptr, my_key_funct, &acc);
	//mlx_mouse_hook(win_ptr, pepe, &acc);
	mlx_loop(mlx_ptr);
	return (0);
}
