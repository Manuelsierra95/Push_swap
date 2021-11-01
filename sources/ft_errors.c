/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:27:24 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/01 19:40:42 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void	ft_errormsg(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

void	ft_is_sorted(t_list **a)
{
	t_list	*aux;

	aux = *a;
	while(aux->next)
	{
		if(aux->content < aux->next->content)
			aux = aux->next;
		else
			break ;
	}
	if(aux->next == NULL)
		exit(0);
}

void	ft_repeatnumbers(t_list **a, int numbers)
{
	t_list	*aux;

	aux = *a;
	if(*a != NULL)
	{
		while(aux != NULL)
		{
			if(aux->content == numbers)
				ft_errormsg();
			aux = aux->next;
		}
	}
}

void	ft_is_double_sign(char *argv)
{
	int	y;

	y = 0;
	while(argv[y])
	{
		if(argv[y] == '-' || argv[y] == '+')
		{
			y++;
			if(argv[y] == '-' || argv[y] == '+')
				ft_errormsg();
			
		}
		y++;
	}
}

void	ft_voidstr(int argc, char **argv)
{
	int	x;
	int	y;
	int	tok;

	tok = 1;
	x = 1;
	while(x < argc)
	{
		y = 0;
		if(ft_strlen(argv[x]) == 0)
			exit(0);
		while(argv[x][y])
		{
			if(argv[x][y] == ' ')
				tok = 0;
			else
				tok = 1;		
			y++;
		}
		if(tok == 0)
			exit(0);
		x++;
	}
}