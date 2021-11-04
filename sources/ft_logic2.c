/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:22:52 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/04 18:33:01 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_execute(t_list **a, t_list **b, int *numbers, int divide)
{
	int				total;
	int				i;
	static t_pivot	pivot;

	pivot.pivot1 = 0;
	pivot.pivot2 = 0;
	i = 1;
	total = ft_lstsize(*a);
	pivot.pivot2 = ((total * i) / divide) - 1;
	while (i < divide)
	{
		ft_quick_sort(a, b, numbers, pivot);
		pivot.pivot1 = (total * i) / divide;
		pivot.pivot2 = (((total * (i + 1))) / divide) - 1;
		i++;
	}
	ft_quick_sort(a, b, numbers, pivot);
	ft_order_a(a, b, numbers, pivot);
}

void	ft_move_b(t_list **b, t_pivot pivot)
{
	if (pivot.position < (ft_lstsize(*b) / 2))
	{
		while (pivot.position != 0)
		{
			ft_rotate_rb(b);
			pivot.position--;
		}
	}
	else
	{
		while (pivot.position != ft_lstsize(*b))
		{
			ft_reverse_rotate_rrb(b);
			pivot.position++;
		}
	}
}

void	ft_move_a(t_list **a, t_pivot pivot)
{
	if (pivot.position < (ft_lstsize(*a) / 2))
	{
		while (pivot.position != 0)
		{
			ft_rotate_ra(a);
			pivot.position--;
		}
	}
	else
	{
		while (pivot.position != ft_lstsize(*a))
		{
			ft_reverse_rotate_rra(a);
			pivot.position++;
		}
	}
}

void	ft_quick_sort(t_list **a, t_list **b, int *numbers, t_pivot pivot)
{
	t_list	*aux;

	aux = *a;
	pivot.position = 0;
	while (aux != NULL)
	{
		if (aux->n <= numbers[pivot.pivot1] && aux->n >= numbers[pivot.pivot2])
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
	ft_order_b(a, b, numbers, pivot);
	ft_return_a(a, b);
}

void	ft_order_b(t_list **a, t_list **b, int *numbers, t_pivot pivot)
{
	int		i;
	t_list	*aux2;

	aux2 = *b;
	pivot.position = 0;
	i = pivot.pivot1;
	while (aux2)
	{
		if (aux2->n == numbers[i] && i < pivot.pivot2)
		{
			ft_move_b(b, pivot);
			ft_push_pa(a, b);
			aux2 = *b;
			pivot.position = 0;
			i++;
		}
		else
		{
			pivot.position++;
			aux2 = aux2->next;
		}
	}
}
