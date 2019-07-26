/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:14:31 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/26 11:21:11 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/main.h"

int		arr_size(char **lst)
{
	int i;

	i = 0;
	while (lst[i])
	{
		i++;
	}
	return (i);
}

void	checker(t_master *master, t_info info)
{
	int x;

	x = 0;
	x = arr_size(info.inf);
	if (x != master->grid.num_x)
	{
		ft_putstr("Incomplete map");
		exit(0);
	}
}
