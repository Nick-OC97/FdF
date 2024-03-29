/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: no-conne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 10:05:15 by no-conne          #+#    #+#             */
/*   Updated: 2019/06/04 10:51:36 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
			i++;
		if ((s1[i] == '\0' && s2[i] == '\0') ||
				(i == n && s1[i - 1] == s2[i - 1]))
			return (1);
		return (0);
	}
	return (0);
}
