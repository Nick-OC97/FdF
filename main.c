/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:07:25 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/05 10:17:20 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "/goinfre/no-conne/Desktop/fdfh/resources/minilibx_macos/mlx.h"
//#include "/goinfre/no-conne/Desktop/fdfh/libft/includes/libft.h"
#include "main.h"

t_point		get_point(char *str) //turns numbers into points that can be worked with
{
	t_point point;
	point.x = str[0];
	point.y = str[1];
	point.z = str[2];
	return (point);
}

char **interpreter(const char* path) //turns input file into a str of numbers
{
	int fd;
	char *line;
	char **inf;
	int x;
	int y;
	char data[50][50];

	x = 0;
	y = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0);
	{
		inf = ft_strsplit(line, ' ');
		while (inf[x][y])
		{
			data[x][y] = ft_atoi(inf[x][y]);
			x++;
		}
		y++;
	}
	return (data);
}

int	my_key_funct(int keycode, void *param) // for escaping to end function
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
	y += 10;
	}
	x = 50;
	while(x <= 450)
	{
		y = 50;
		while (y <= 450)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
			y++;
		}
	x += 10;
	}
	mlx_key_hook(win_ptr, my_key_funct, &acc);
	mlx_loop(mlx_ptr);
	return (0);
}
