/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:22:52 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/03 21:13:36 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void	ft_execute(t_list **a, t_list **b, int *numbers, int divide)
{
	// int	pivot1;
	// int	pivot2;
	// int	pivot3;
	int	total;
	int	i;
	static t_pivot	pivot;
	
	pivot.pivot1 = 0;
	pivot.pivot2 = 0;
	i = 1;
	total = ft_lstsize(*a);
	pivot.pivot2 = ((total * i) / divide) - 1;
	while(i < divide)
	{
		
		ft_quick_sort(a, b, numbers, pivot);
		pivot.pivot1 = (total * i) / divide;
		pivot.pivot2 = (((total * (i + 1))) / divide) - 1;
		i++;
	}
	ft_quick_sort(a, b, numbers, pivot);
	// pivot1 = (ft_lstsize(*a) * 1) / 4;
	// pivot2 = (ft_lstsize(*a) * 2) / 4;
	// pivot3 = (ft_lstsize(*a) * 3) / 4;
	// ft_quick_sort(a, b, numbers);
	// ft_quick_sort(a, b, numbers);
	// ft_quick_sort(a, b, numbers);
	ft_order_a(a, b, numbers, pivot);
}

int	ft_hightop(t_list **a, t_list **b, t_pivot pivot, int *numbers)
{
	if((*a)->content <= numbers[pivot.pivot1] && (*a)->content >= numbers[pivot.pivot2])
	{
		ft_push_pb(a, b);
		return (1);
	}
	else
		return (0);
}

void	ft_move_b(t_list **b, t_pivot pivot)
{
	if(pivot.position < (ft_lstsize(*b) / 2))
	{
		while(pivot.position != 0)
		{
			ft_rotate_rb(b);
			pivot.position--;
		}
	}
	else
	{
		while(pivot.position != ft_lstsize(*b))
		{
			ft_reverse_rotate_rrb(b);
			pivot.position++;
		}

	}
}

void	ft_move_a(t_list **a, t_list **b, t_pivot pivot, int *numbers)
{
	if(pivot.position < (ft_lstsize(*a) / 2))
	{
		while(pivot.position != 0)
		{
			pivot.position = pivot.position - ft_hightop(a, b, pivot, numbers);
			ft_rotate_ra(a);
			pivot.position--;
		}
	}
	else
	{
		while(pivot.position != ft_lstsize(*a))
		{
			// ft_hightop(a, b, pivot, numbers);
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
	// printf("**Pivot1: %d\tPivot2: %d\n", pivot.pivot1, pivot.pivot2);
	while(aux != NULL)
	{
		if(aux->content <= numbers[pivot.pivot1] && aux->content >= numbers[pivot.pivot2])
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

	// t_list *aux3;
	// aux3 = *b;
	// while(aux3)
	// {
	// 	printf("b: %d\n", aux3->content);
	// 	aux3 = aux3->next;
	// }
	ft_order_b(a, b, numbers, pivot);
	ft_return_a(a, b);
	// t_list *aux4;
	// aux4 = *a;
	// while(aux4)
	// {
	// 	printf("a: %d\n", aux4->content);
	// 	aux4 = aux4->next;
	// }
}

void	ft_order_b(t_list **a, t_list **b, int *numbers, t_pivot pivot)
{
	int		i;
	t_list	*aux2;

	aux2 = *b;
	pivot.position = 0;
	i = pivot.pivot1;
	while(aux2)
	{
		if(aux2->content == numbers[i] && i < pivot.pivot2)
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
