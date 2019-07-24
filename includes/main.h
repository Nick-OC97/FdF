/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:07:49 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/24 16:08:14 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../libft/includes/libft.h"
# include "../resources/minilibx_macos/mlx.h"
# include "../libvec_lib/includes/libvec.h"
# include <math.h>
# define WIN_H 800
# define WIN_W 800

typedef struct s_mlx_acc
{
	void 	*mlx_ptr;
	void	*win_ptr;
}			t_mlx_acc;

typedef struct s_grid_sizes
{
	int		num_x;
	int		num_y;
	int		num_tot;
}				t_grid_sizes;

typedef struct s_info
{
	int		x_size;
	int		total_size;
	int		y_size;
	int		fd;
	char	*line;
	char	**inf;
}				t_info;

typedef struct s_image
{
	void		*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	char		*raw_data;
	int			width;
	int			height;
	t_point		pos;
}				t_image;

typedef struct s_master
{
	t_mlx_acc		acc;
	t_grid_sizes	grid;
	t_image			img;
	float			xt;
	float			yt;
	float			zt;
	float			xa;
	float			ya;
	float			za;
	float			trans_x;
	float			trans_y;
	float			trans_z;
	t_point			*screen_coords;
	t_point			*original_coords;
}				t_master;

void				draw_func(t_master *master);
t_grid_sizes		ft_lstnew_fdf(int x_size, int y_size, int total_size);
t_grid_sizes		get_sizes(char *path);
void				interpreter(const char* path, t_master *master);
void				translator(t_master *master);
void				clear_image(t_image *img, int color);
void				init_img(t_mlx_acc acc, t_image *img, int width, int height);
void				put_pxlto_img(t_image *img, int color, int x, int y);
void				put_img(t_mlx_acc acc, t_image *img);
#endif