/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:01:29 by msierra-          #+#    #+#             */
/*   Updated: 2021/10/29 20:25:31 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_parseint(int argc, char **argv, t_list **a);
int		ft_is_char(char c);

void	ft_parseint(int argc, char **argv, t_list **a)
{
	int	y;
	int i;
	int j;

	while(1 < argc--)
	{
		y = 0;
		i = 0;
		while(argv[argc][y])
		{
			j = 0;
			if(ft_is_char(argv[argc][y]))
			{
				y++;
				j++;
				if(ft_is_char(argv[argc][y]))
					ft_errormsg();
			}
			while(argv[argc][y] == ' ' && argv[argc][y++])
				i++;
			while((argv[argc][y] >= '0' && argv[argc][y] <= '9') && argv[argc][y++])	
				j++;		
			ft_add_a(ft_substr(argv[argc], i, (j + i)), a);
			i = i + j;
		}
	}
}

int	ft_is_char(char c)
{
	if(c == '-' || c == '+')
		return (1);
	else if((c >= '0' && c <= '9') || c == ' ')
		return (0);
	return (0);
}

