/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:27:24 by msierra-          #+#    #+#             */
/*   Updated: 2021/10/29 18:50:46 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
