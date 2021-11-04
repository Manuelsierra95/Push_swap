/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:49:40 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/04 18:33:11 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate_ra(t_list **a)
{
	t_list	*aux;

	if (ft_lstsize(*a) > 1)
	{
		aux = *a;
		ft_lstadd_back(a, aux);
		*a = (*a)->next;
		aux->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	ft_rotate_rb(t_list **b)
{
	t_list	*aux;

	if (ft_lstsize(*b) > 1)
	{
		aux = *b;
		ft_lstadd_back(b, aux);
		*b = (*b)->next;
		aux->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	ft_rotate_rr(t_list **a, t_list **b)
{
	t_list	*aux;

	if (ft_lstsize(*a) > 1)
	{
		aux = *a;
		ft_lstadd_back(a, aux);
		*a = (*a)->next;
		aux->next = NULL;
		aux = *b;
		ft_lstadd_back(b, aux);
		*b = (*b)->next;
		aux->next = NULL;
		write(1, "rr\n", 3);
	}
}

void	ft_reverse_rotate_rra(t_list **a)
{
	t_list	*last;
	t_list	*aux;

	if (ft_lstsize(*a) > 1)
	{
		aux = *a;
		last = ft_lstlast(*a);
		while (aux->next->next)
			aux = aux->next;
		aux->next = NULL;
		ft_lstadd_front(a, last);
		write(1, "rra\n", 4);
	}
}

void	ft_reverse_rotate_rrb(t_list **b)
{
	t_list	*last;
	t_list	*aux;

	if (ft_lstsize(*b) > 1)
	{
		aux = *b;
		last = ft_lstlast(*b);
		while (aux->next->next)
			aux = aux->next;
		aux->next = NULL;
		ft_lstadd_front(b, last);
		write(1, "rrb\n", 4);
	}
}
