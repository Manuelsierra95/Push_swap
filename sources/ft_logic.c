/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:35:15 by msierra-          #+#    #+#             */
/*   Updated: 2021/10/30 20:59:12 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void	ft_move_a(t_list **a, t_list **b, int position)
{
	if(position < (ft_lstsize(*a) / 2))
	{
		while(position != 0)
		{
			ft_rotate_ra(a);
			position--;
		}
	}
	else
	{
		while(position != ft_lstsize(*a))
		{
			ft_reverse_rotate_rra(a);
			position++;
		}

	}
}

void	ft_compare(t_list **a, t_list **b, int *numbers)
{
	int		i;
	int		position;
	t_list	*aux;

	aux = *a;
	position = 0;
	i = 0;
	while(aux != NULL)
	{
		if(aux->content == numbers[i])
		{
			ft_move_a(a, b, position);
			ft_push_pb(a, b);
			aux = (*a)->head;
			position = 0;
			i++;
		}
		if(aux->content == numbers[i])
		{
			ft_move_a(a, b, position);
			ft_push_pb(a, b);
		}
		position++;
		aux = aux->next;
	}
}

void	ft_return_a(t_list **a, t_list **b)
{
	while(*b)
	{
		ft_push_pa(a, b);
	}
}