/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:35:15 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/03 20:38:35 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void	ft_order_5_3(t_list **a, int *numbers)
{
	if((*a)->content == numbers[2])
	{
		if((*a)->next->content == numbers[4])
			ft_rotate_ra(a);
		else if((*a)->next->content == numbers[3])
		{
			ft_swap_sa(a);
			ft_reverse_rotate_rra(a);
		}
	}
	else if((*a)->content == numbers[3])
	{
		if((*a)->next->content == numbers[4])
			ft_swap_sa(a);
		else if((*a)->next->content == numbers[2])
			ft_reverse_rotate_rra(a);
	}
	else if((*a)->content == numbers[4] && (*a)->next->content == numbers[2])
	{
			ft_reverse_rotate_rra(a);
			ft_swap_sa(a);
	}
}

void	ft_order_3(t_list **a, int *numbers)
{
	if((*a)->content == numbers[0])
	{
		if((*a)->next->content == numbers[2])
			ft_rotate_ra(a);
		else if((*a)->next->content == numbers[1])
		{
			ft_swap_sa(a);
			ft_reverse_rotate_rra(a);
		}
	}	
	else if((*a)->content == numbers[1])
	{
		if((*a)->next->content == numbers[2])
			ft_swap_sa(a);
		else if((*a)->next->content == numbers[0])
			ft_reverse_rotate_rra(a);
	}
	else if((*a)->content == numbers[2] && (*a)->next->content == numbers[0])
	{
			ft_reverse_rotate_rra(a);
			ft_swap_sa(a);
	}
}

void	ft_order_4(t_list **a, t_list **b, int *numbers)
{
	t_list	*aux;
	t_pivot	pivot;
	int		i;

	i = 0;
	pivot.position = 0;
	aux = *a;
	while(aux != NULL)
	{
		if(aux->content == numbers[i] && i < 1)
		{
			ft_move_a(a, b, pivot, numbers);
			ft_push_pb(a, b);
			aux = *a;
			pivot.position = 0;
			i++;
		}
		else
		{
			pivot.position++;
			aux = aux->next;	
		}
	}
	ft_order_5_3(a, numbers);
}

void	ft_order_5(t_list **a, t_list **b, int *numbers)
{
	t_list	*aux;
	t_pivot	pivot;

	pivot.position = 0;
	aux = *a;
	while(aux != NULL)
	{
		if(aux->content <= numbers[4] && aux->content >= numbers[2])
		{
			ft_move_a(a, b, pivot, numbers);
			ft_push_pb(a, b);
			aux = *a;
			pivot.position = 0;
		}
		else
		{
			pivot.position++;
			aux = aux->next;	
		}
	}
	ft_order_5_3(b, numbers);
}

void	ft_order_a(t_list **a, t_list **b, int *numbers, t_pivot pivot)
{
	int		i;
	t_list	*aux;

	aux = *a;
	pivot.position = 0;
	i = pivot.pivot2;
	while(aux != NULL)
	{
		if(aux->content == numbers[i] && i >= pivot.pivot1)
		{
			ft_move_a(a, b, pivot, numbers);
			ft_push_pb(a, b);
			aux = *a;
			pivot.position = 0;
			i--;
		}
		else
		{
			pivot.position++;
			aux = aux->next;	
		}
	}
}
