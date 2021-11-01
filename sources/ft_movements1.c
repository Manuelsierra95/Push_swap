/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:06:46 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/01 18:30:42 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_swap_sa(t_list **a)
{
	t_list	*aux;

	if(ft_lstsize(*a) > 1)
	{
		aux = *a;
		*a = (*a)->next;
		aux->next = (*a)->next;
		(*a)->next = aux;
		write(1, "sa\n", 3);	
	}
}

void ft_swap_sb(t_list **b)
{
	t_list	*aux;

	if(ft_lstsize(*b) > 1)
	{
		aux = *b;
		(*b) = (*b)->next;
		aux->next = (*b)->next;
		(*b)->next = aux;
		write(1, "sb\n", 3);
	}
}

void ft_swap_ss(t_list **a, t_list **b)
{
	t_list	*aux;

	if(ft_lstsize(*a) > 1 || ft_lstsize(*b) > 1)
	{
		aux = *a;
		(*a) = (*a)->next;
		aux->next = (*a)->next;
		(*a)->next = aux;
		aux = *b;
		(*b) = (*b)->next;
		aux->next = (*b)->next;
		(*b)->next = aux;
		write(1, "ss\n", 3);
	}
}

void ft_push_pa(t_list **a, t_list **b)
{
	t_list	*aux;

	if(ft_lstsize(*b) > 0)
	{
		aux = *b;
		*b = (*b)->next;
		ft_lstadd_front(a, aux);
		write(1, "pa\n", 3);
	}
}

void ft_push_pb(t_list **a, t_list **b)
{
	t_list	*aux;

	if(ft_lstsize(*a) > 0)
	{
		aux = *a;
		*a = (*a)->next;
		ft_lstadd_front(b, aux);
		write(1, "pb\n", 3);
	}
}
