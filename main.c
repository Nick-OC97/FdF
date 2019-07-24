/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:07:25 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/24 10:50:44 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"
#include <stdio.h>

void	move_func_l(t_master *master)
{
	int x;
	t_matrix	trans;

	x = 0;
	trans = make_translate_matrix(-10, 0, 0);
	while (x < (master->grid.num_tot))
	{
		//lst[x] = scalar_vec_multiply(lst[x], 20);
		//lst[x] = matrix_vecmultiply(lst[x], rot);
		//lst[x] = matrix_vecmultiply(lst[x], rot2);
		master->lst[x] = matrix_vecmultiply(master->lst[x], trans);
		x++;
	}
	clear_image(&master[0].img, 0x000000);
	draw_func(master[0]);
	put_img(master[0].acc, &master[0].img);
}

void	move_func_r(t_master *master)
{
	int x;
	t_matrix	trans;

	x = 0;
	trans = make_translate_matrix(10, 0, 0);
	while (x < (master->grid.num_tot))
	{
		//lst[x] = scalar_vec_multiply(lst[x], 20);
		//lst[x] = matrix_vecmultiply(lst[x], rot);
		//lst[x] = matrix_vecmultiply(lst[x], rot2);
		master->lst[x] = matrix_vecmultiply(master->lst[x], trans);
		x++;
	}
	clear_image(&master[0].img, 0x000000);
	draw_func(master[0]);
	put_img(master[0].acc, &master[0].img);
}

void	move_func_u(t_master *master)
{
	int x;
	t_matrix	trans;

	x = 0;
	trans = make_translate_matrix(0, 10, 0);
	while (x < (master->grid.num_tot))
	{
		//lst[x] = scalar_vec_multiply(lst[x], 20);
		//lst[x] = matrix_vecmultiply(lst[x], rot);
		//lst[x] = matrix_vecmultiply(lst[x], rot2);
		master->lst[x] = matrix_vecmultiply(master->lst[x], trans);
		x++;
	}
	clear_image(&master[0].img, 0x000000);
	draw_func(master[0]);
	put_img(master[0].acc, &master[0].img);
}

void	move_func_d(t_master *master)
{
	int x;
	t_matrix	trans;

	x = 0;
	trans = make_translate_matrix(0, -10, 0);
	while (x < (master->grid.num_tot))
	{
		//lst[x] = scalar_vec_multiply(lst[x], 20);
		//lst[x] = matrix_vecmultiply(lst[x], rot);
		//lst[x] = matrix_vecmultiply(lst[x], rot2);
		master->lst[x] = matrix_vecmultiply(master->lst[x], trans);
		x++;
	}
	clear_image(&master[0].img, 0x000000);
	draw_func(master[0]);
	put_img(master[0].acc, &master[0].img);
}

void	scale_func_s(t_master *master)
{
	int x;

	x = 0;
	while (x < (master->grid.num_tot))
	{
		master->lst[x] = scalar_vec_multiply(master->lst[x], 0.5);
		//lst[x] = matrix_vecmultiply(lst[x], rot);
		//lst[x] = matrix_vecmultiply(lst[x], rot2);
		x++;
	}
	clear_image(&master[0].img, 0x000000);
	draw_func(master[0]);
	put_img(master[0].acc, &master[0].img);
}

void	scale_func_l(t_master *master)
{
	int x;

	x = 0;
	while (x < (master->grid.num_tot))
	{
		master->lst[x] = scalar_vec_multiply(master->lst[x], 1.5);
		//lst[x] = matrix_vecmultiply(lst[x], rot);
		//lst[x] = matrix_vecmultiply(lst[x], rot2);
		x++;
	}
	clear_image(&master[0].img, 0x000000);
	draw_func(master[0]);
	put_img(master[0].acc, &master[0].img);
}

int	my_key_funct(int keycode, t_master *master)
{
	ft_putstr("Key event: ");
	ft_putnbr(keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		move_func_l(master);
	if (keycode == 124)
		move_func_r(master);
	if (keycode == 125)
		move_func_u(master);
	if (keycode == 126)
		move_func_d(master);
	if (keycode == 78)
		scale_func_s(master);
	if (keycode == 69)
		scale_func_l(master);
	return (1);
}

int	main(int argc, char **argv)
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_master		master;

	if (argc != 2)
	{
		ft_putstr("Wrong number of arguments");
		return (0);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_H, WIN_W, "NICK");
	master.acc.mlx_ptr = mlx_ptr;
	master.acc.win_ptr = win_ptr;
	init_img(master.acc, &master.img, WIN_W, WIN_H);
	clear_image(&master.img, 0x000000);
	master.grid = get_sizes(argv[1]);
	master.lst = interpreter(argv[1], master.grid);
	translator(master);
	put_img(master.acc, &master.img);
	//mlx_key_hook(win_ptr, move_func_l, &master);
	//mlx_key_hook(win_ptr, my_key_funct, &master);
	mlx_hook(win_ptr, 2, 0, my_key_funct,&master);
	//mlx_hook(win_ptr, 2, 0, move_func_l,&master);
	mlx_loop(mlx_ptr);
	return (0);
}
