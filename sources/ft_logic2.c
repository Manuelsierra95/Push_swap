/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:22:52 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/02 18:35:28 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void	ft_execute(t_list **a, t_list **b, int *numbers)
{
	int	pivot1;
	int	pivot2;
	int	pivot3;
	int	total;

	total = ft_lstsize(*a);
	pivot1 = (ft_lstsize(*a) * 1) / 4;
	pivot2 = (ft_lstsize(*a) * 2) / 4;
	pivot3 = (ft_lstsize(*a) * 3) / 4;
	ft_quick_sort(a, b, numbers, 0, pivot1 - 1);
	ft_quick_sort(a, b, numbers, pivot1, pivot2 - 1);
	ft_quick_sort(a, b, numbers, pivot2, pivot3 - 1);
	ft_quick_sort(a, b, numbers, pivot3, total - 1);
	ft_order_a(a, b, numbers, pivot3, total - 1);
}

void	ft_move_b(t_list **b, int position)
{
	if(position < (ft_lstsize(*b) / 2))
	{
		while(position != 0)
		{
			ft_rotate_rb(b);
			position--;
		}
	}
	else
	{
		while(position != ft_lstsize(*b))
		{
			ft_reverse_rotate_rrb(b);
			position++;
		}

	}
}

void	ft_quick_sort(t_list **a, t_list **b, int *numbers, int pivot1, int pivot2)
{
	int	position;
	t_list	*aux;

	aux = *a;
	position = 0;
	while(aux != NULL)
	{
		if(aux->content <= numbers[pivot1] && aux->content >= numbers[pivot2])
		{
			ft_move_a(a, position);
			ft_push_pb(a, b);
			aux = *a;
			position = 0;
		}
		else
		{
			position++;
			aux = aux->next;
		}
	}
	ft_order_b(a, b, numbers, pivot1, pivot2);
	ft_return_a(a, b);
}

void	ft_order_b(t_list **a, t_list **b, int *numbers, int pivot1, int pivot2)
{
	int		i;
	int		position;
	t_list	*aux2;

	aux2 = *b;
	position = 0;
	i = pivot1;
	while(aux2)
	{
		if(aux2->content == numbers[i] && i < pivot2)
		{
			ft_move_b(b, position);
			ft_push_pa(a, b);
			aux2 = *b;
			position = 0;
			i++;
		}
		else
		{
			position++;
			aux2 = aux2->next;	
		}
	}
}
