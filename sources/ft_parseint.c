/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:01:29 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/02 13:51:00 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void	ft_parseint(int argc, char **argv, t_list **a)
{
	int	y;
	int i;
	int j;
	int	x;

	x = 1;
	while(x < argc)
	{
		y = 0;
		i = 0;
		while(argv[x][y])
		{
			j = 0;
			ft_is_double_sign(argv[x]);
			while(argv[x][y] == ' ' && argv[x][y++])
				i++;
			while(((argv[x][y] >= '0' && argv[x][y] <= '9') || argv[x][y] == '-' || argv[x][y] == '+') 
					&& argv[x][y++])	
				j++;
			if(j > 0)
				ft_add_a(ft_substr(argv[x], i, (j + i)), a);
			i = i + j;
		}
		x++;
	}
}
