/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:35:15 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/04 18:32:55 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_order_3(t_list **lst)
{
	if ((*lst)->n > (*lst)->next->n && (*lst)->n > (*lst)->next->next->n)
	{
		if ((*lst)->next->n < (*lst)->next->next->n)
			ft_rotate_ra(lst);
		else if ((*lst)->next->n > (*lst)->next->next->n)
		{
			ft_swap_sa(lst);
			ft_reverse_rotate_rra(lst);
		}
	}
	else if ((*lst)->n < (*lst)->next->n && (*lst)->n < (*lst)->next->next->n)
	{
		if ((*lst)->next->n > (*lst)->next->next->n)
		{
			ft_reverse_rotate_rra(lst);
			ft_swap_sa(lst);
		}
	}
	else
	{
		if ((*lst)->n > (*lst)->next->n)
			ft_swap_sa(lst);
		else if ((*lst)->n < (*lst)->next->n)
			ft_reverse_rotate_rra(lst);
	}
}

void	ft_order_4(t_list **a, t_list **b, int *numbers)
{
	t_list	*aux;
	t_pivot	pivot;

	pivot.position = 0;
	aux = *a;
	while (aux != NULL)
	{
		if (aux->n == numbers[3])
		{
			ft_move_a(a, pivot);
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
	ft_order_3(a);
	ft_return_a(a, b);
}

void	ft_order_5(t_list **a, t_list **b, int *numbers)
{
	t_list	*aux;
	t_pivot	pivot;
	int		i;

	i = 4;
	pivot.position = 0;
	aux = *a;
	while (aux != NULL)
	{
		if (aux->n == numbers[i] && i >= 3)
		{
			ft_move_a(a, pivot);
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
	ft_order_3(a);
	ft_return_a(a, b);
}

void	ft_order_a(t_list **a, t_list **b, int *numbers, t_pivot pivot)
{
	int		i;
	t_list	*aux;

	aux = *a;
	pivot.position = 0;
	i = pivot.pivot2;
	while (aux != NULL)
	{
		if (aux->n == numbers[i] && i >= pivot.pivot1)
		{
			ft_move_a(a, pivot);
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
