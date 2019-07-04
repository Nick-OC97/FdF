/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:07:25 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/04 12:46:30 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/goinfre/no-conne/Desktop/fdfh/resources/minilibx_macos/mlx.h"


int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int x;
	int y;

	mlx_ptr = mlx_init();
	y = 50;
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "NICK");
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
	mlx_loop(mlx_ptr);
	return (0);
}
