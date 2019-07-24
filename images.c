/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:04:15 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/24 07:55:16 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"

void	clear_image(t_image *img, int color)
{
	int		*data;
	int		i;

	data = (int *)img->raw_data;
	i = 0;
	while (i < (img->width * img->height))
	{
		data[i] = color;
		i++;
	}
}

void	init_img(t_mlx_acc acc, t_image *img, int width, int height)
{
	img->img_ptr = mlx_new_image(acc.mlx_ptr, width, height);
	img->raw_data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_line,
	&img->endian);
	img->width = width;
	img->height = height;
	img->pos.x = 0;
	img->pos.y = 0;
	clear_image(img, 0x000000);
}

void	put_pxlto_img(t_image *img, int color, int x, int y)
{
	int		*data;

	if (x >= img->width || x < 0)
		return ;
	if (y >= img->height || y < 0)
		return ;
	data = (int *)&img->raw_data[x * 4 + y * img->size_line];
	*data = color;
}

void	put_img(t_mlx_acc acc, t_image *img)
{
	mlx_put_image_to_window(acc.mlx_ptr, acc.win_ptr, img->img_ptr,
	img->pos.x, img->pos.y);
}
