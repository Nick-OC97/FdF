/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:07:25 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/24 16:36:18 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"
#include <stdio.h>

void	move_func_l(t_master *master)
{
	master->trans_x = master->trans_x - 10;
	translator(master);
	clear_image(&master->img, 0x000000);
	draw_func(master);
	put_img(master[0].acc, &master->img);
}

void	move_func_r(t_master *master)
{
	master->trans_x = master->trans_x + 10;
	translator(master);
	clear_image(&master->img, 0x000000);
	draw_func(master);
	put_img(master[0].acc, &master->img);
}

void	move_func_u(t_master *master)
{
	master->trans_y = master->trans_y + 10;
	translator(master);
	clear_image(&master->img, 0x000000);
	draw_func(master);
	put_img(master[0].acc, &master->img);
}

void	move_func_d(t_master *master)
{
	master->trans_y = master->trans_y - 10;
	translator(master);
	clear_image(&master->img, 0x000000);
	draw_func(master);
	put_img(master[0].acc, &master->img);
}

void	scale_func_s(t_master *master)
{
	master->xt *= 0.9;
	master->yt *= 0.9;
	translator(master);
	clear_image(&master->img, 0x000000);
	draw_func(master);
	put_img(master[0].acc, &master->img);
}

void	scale_func_l(t_master *master)
{
	master->xt *= 1.1;
	master->yt *= 1.1;
	translator(master);
	clear_image(&master->img, 0x000000);
	draw_func(master);
	put_img(master[0].acc, &master->img);
}

void	rot_func_x(t_master *master)
{
	master->xa = master->xa + 0.1;
	translator(master);
	clear_image(&master->img, 0x000000);
	draw_func(master);
	put_img(master->acc, &master->img);
}

void	rot_func_y(t_master *master)
{
	master->ya = master->ya + 0.1;
	translator(master);
	clear_image(&master->img, 0x000000);
	draw_func(master);
	put_img(master->acc, &master->img);
}

int	my_key_funct(int keycode, t_master *master)
{
	//ft_putstr("Key event: ");
	//ft_putnbr(keycode);
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
	if (keycode == 12)
		rot_func_x(master);
	if (keycode == 13)
		rot_func_y(master);
	return (1);
}

void	init_master(t_master *master)
{
	master->za = 0;
	master->xa = 0.75;
	master->ya = -0.75;
	master->xt = 10;
	master->yt = 10;
	master->zt = 10;
	master->trans_x = (WIN_W / 2 - master->grid.num_x / 2);
	master->trans_y = (WIN_H / 2 - master->grid.num_y / 2);
	master->trans_z = 0;
}

int	main(int argc, char **argv)
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_master		master;
	int x;

	x = 0;
	if (argc != 2)
	{
		ft_putstr("Wrong number of arguments");
		return (0);
	}
	init_master(&master);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_H, WIN_W, "fdf");
	master.acc.mlx_ptr = mlx_ptr;
	master.acc.win_ptr = win_ptr;
	init_img(master.acc, &master.img, WIN_W, WIN_H);
	clear_image(&master.img, 0x000000);
	master.grid = get_sizes(argv[1]);
	interpreter(argv[1], &master);
	translator(&master);
	put_img(master.acc, &master.img);
	mlx_hook(win_ptr, 2, 0, my_key_funct,&master);
	mlx_loop(mlx_ptr);
	return (0);
}
