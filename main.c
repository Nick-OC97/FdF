/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:07:25 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/22 14:57:29 by no-conne         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_mlx_acc		acc;
	t_point			*lst;
	t_grid_sizes	grid;

	if (argc != 2)
	{
		ft_putstr("Wrong number of arguments");
		return (0);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 600, 600, "NICK");
	acc.mlx_ptr = mlx_ptr;
	acc.win_ptr = win_ptr;
	grid = get_sizes(argv[1]);
	lst = interpreter(argv[1], grid);
	translator(lst, acc, grid);
	mlx_key_hook(win_ptr, my_key_funct, &acc);
	mlx_loop(mlx_ptr);
	return (0);
}
