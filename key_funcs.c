/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 07:44:54 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/26 07:46:21 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"

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
