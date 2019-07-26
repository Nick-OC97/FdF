/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 07:46:35 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/26 07:47:47 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"

void	scale_func_l(t_master *master)
{
	master->xt *= 1.1;
	master->yt *= 1.1;
	translator(master);
	clear_image(&master->img, 0x000000);
	draw_func(master);
	put_img(master[0].acc, &master->img);
}

void	rot_func_xu(t_master *master)
{
	master->xa = master->xa + 0.1;
	translator(master);
	clear_image(&master->img, 0x000000);
	draw_func(master);
	put_img(master->acc, &master->img);
}

void	rot_func_xd(t_master *master)
{
	master->xa = master->xa - 0.1;
	translator(master);
	clear_image(&master->img, 0x000000);
	draw_func(master);
	put_img(master->acc, &master->img);
}
