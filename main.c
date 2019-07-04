/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:07:25 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/04 09:42:01 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/goinfre/no-conne/Desktop/fdfh/resources/minilibx_macos/mlx.h"


int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 200, 200, "NICK");
	mlx_loop(mlx_ptr);
	return (0);
}
