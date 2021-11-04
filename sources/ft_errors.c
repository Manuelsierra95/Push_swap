/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:27:24 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/04 18:32:48 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_errormsg(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

void	ft_is_sorted(t_list **a)
{
	t_list	*aux;

	aux = *a;
	while (aux->next)
	{
		if (aux->n < aux->next->n)
			aux = aux->next;
		else
			break ;
	}
	if (aux->next == NULL)
		exit (0);
}

void	ft_repeatnumbers(t_list **a, int numbers)
{
	t_list	*aux;

	aux = *a;
	if (*a != NULL)
	{
		while (aux != NULL)
		{
			if (aux->n == numbers)
				ft_errormsg();
			aux = aux->next;
		}
	}
}

void	ft_char_error(char *argv)
{
	int	y;

	y = 0;
	while (argv[y])
	{
		if (argv[y] == '-' || argv[y] == '+')
		{
			y++;
			if (argv[y] == '-' || argv[y] == '+')
				ft_errormsg();
		}
		if (!((argv[y] >= '0' && argv[y] <= '9') || (argv[y] == '-'
					|| argv[y] == '+' || argv[y] == ' ')))
			ft_errormsg();
		y++;
	}
}

void	ft_voidstr(int argc, char **argv, int flag)
{
	int	x;
	int	y;

	x = 1;
	while (x < argc)
	{
		y = 0;
		if (ft_strlen(&argv[x][y]) == 0)
			exit(0);
		while (argv[x][y])
		{
			if (argv[x][y] >= '0' && argv[x][y] <= '9')
			{
				flag = 1;
				break ;
			}
			else if (ft_voidstr2(argv[x]))
				flag = 0;
			y++;
		}
		if (flag == 0)
			exit(0);
		x++;
	}
}
