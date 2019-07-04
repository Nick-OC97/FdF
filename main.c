/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:07:25 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/04 14:45:52 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "/goinfre/no-conne/Desktop/fdfh/resources/minilibx_macos/mlx.h"
//#include "/goinfre/no-conne/Desktop/fdfh/libft/includes/libft.h"
#include "main.h"

int	my_key_funct(int keycode, void *param)
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

	mlx_ptr = mlx_init();
	y = 50;
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "NICK");
	acc.mlx_ptr = mlx_ptr;
	acc.win_ptr = win_ptr;
	while (y <= 450)
	{
		x = 50;
		while (x <= 450)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
			x++;
		}
	y++;
	}
	mlx_key_hook(win_ptr, my_key_funct, &acc);
	mlx_loop(mlx_ptr);
	return (0);
}
