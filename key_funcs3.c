/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 07:48:15 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/26 07:54:44 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"

void	rot_func_yl(t_master *master)
{
	master->ya = master->ya + 0.1;
	translator(master);
	clear_image(&master->img, 0x000000);
	draw_func(master);
	put_img(master->acc, &master->img);
}

void	rot_func_yr(t_master *master)
{
	master->ya = master->ya - 0.1;
	translator(master);
	clear_image(&master->img, 0x000000);
	draw_func(master);
	put_img(master->acc, &master->img);
}

void	color_func(t_master *master, int keycode)
{
	if (keycode == 18)
		master->colour = 0xFF0000;
	if (keycode == 19)
		master->colour = 0x00FF00;
	if (keycode == 20)
		master->colour = 0x0000FF;
	translator(master);
	clear_image(&master->img, 0x000000);
	draw_func(master);
	put_img(master->acc, &master->img);
}
