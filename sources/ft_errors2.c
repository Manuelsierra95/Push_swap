/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:47:03 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/04 18:10:25 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_voidstr2(char *argv)
{
	int	y;
	int	flag;

	flag = 1;
	y = 0;
	while (argv[y])
	{
		if (argv[y] == ' ')
			flag = 1;
		else if (!((argv[y] >= '0' && argv[y] <= '9')
				|| (argv[y] == '-' || argv[y] == '+' || argv[y] == ' ')))
			ft_errormsg();
		y++;
	}
	return (flag);
}
