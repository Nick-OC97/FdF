/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:07:25 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/24 08:22:44 by no-conne         ###   ########.fr       */
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
		draw_func(master[0]);
		put_img(master[0].acc, &master[0].img);
	}
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
	mlx_key_hook(win_ptr, my_key_funct, &master.acc);
	mlx_key_hook(win_ptr, move_func, &master);
	mlx_loop(mlx_ptr);
	return (0);
}
