/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <no-conne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:07:49 by no-conne          #+#    #+#             */
/*   Updated: 2019/07/04 14:42:31 by no-conne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft/includes/libft.h"
# include "resources/minilibx_macos/mlx.h"

typedef struct s_mlx_acc
{
	void 	*mlx_ptr;
	void	*win_ptr;
}			t_mlx_acc;

#endif