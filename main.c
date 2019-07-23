/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:07:25 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/23 12:01:38 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"
#include <stdio.h>

int	my_key_funct(int keycode, void *param)
{
	t_mlx_acc	*acc;

	acc = param;
	ft_putstr("Key event: ");
	ft_putnbr(keycode);
	if (keycode == 53)
		exit(0);
	return (1);
}

int	move_func(int keycode, void *param)
{
	int x;
	t_matrix	trans;
	t_master	*master;

	master = param;
	x = 0;
	if (keycode == 123)
	{
		trans = make_translate_matrix(-10, 0, 0);
		while (x < (master->grid.num_tot))
		{
			//lst[x] = scalar_vec_multiply(lst[x], 20);
			//lst[x] = matrix_vecmultiply(lst[x], rot);
			//lst[x] = matrix_vecmultiply(lst[x], rot2);
			master->lst[x] = matrix_vecmultiply(master->lst[x], trans);
			x++;
		}
		draw_func(master->lst, master->grid, master->acc);
	}
	return (1);
} 

int	main(int argc, char **argv)
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_mlx_acc		acc;
	t_point			*lst;
	t_grid_sizes	grid;
	t_master		master;

	if (argc != 2)
	{
		ft_putstr("Wrong number of arguments");
		return (0);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_H, WIN_W, "NICK");
	acc.mlx_ptr = mlx_ptr;
	acc.win_ptr = win_ptr;
	grid = get_sizes(argv[1]);
	lst = interpreter(argv[1], grid);
	translator(lst, acc, grid);
	master.acc = acc;
	master.grid = grid;
	master.lst = lst;
	mlx_key_hook(win_ptr, my_key_funct, &acc);
	mlx_key_hook(win_ptr, move_func, &master);
	mlx_loop(mlx_ptr);
	return (0);
}
