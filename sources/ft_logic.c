/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:35:15 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/01 19:31:35 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void	ft_move_a(t_list **a, int position)
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

void	ft_order_5_3(t_list **a, int *numbers)
{
	if((*a)->content == numbers[2] && (*a)->next->content == numbers[4])
	{
			ft_reverse_rotate_rra(a);
			ft_swap_sa(a);
	}
	else if((*a)->content == numbers[3])
	{
		if((*a)->next->content == numbers[2])
			ft_swap_sa(a);
		else
			ft_reverse_rotate_rra(a);
	}
	else if((*a)->content == numbers[4])
	{
		if((*a)->next->content == numbers[2])
		{
			ft_reverse_rotate_rra(a);
			ft_reverse_rotate_rra(a);
		}
		else
		{
			ft_swap_sa(a);
			ft_reverse_rotate_rra(a);
		}
	}
}

void	ft_order_3(t_list **a, int *numbers)
{
	if((*a)->content == numbers[0])
	{
		ft_reverse_rotate_rra(a);
		ft_swap_sa(a);
	}	
	else if((*a)->content == numbers[1])
	{
		if((*a)->next->content == numbers[0])
			ft_swap_sa(a);
		else
			ft_reverse_rotate_rra(a);
	}
	else if((*a)->content == numbers[2])
	{
		if((*a)->next->content == numbers[0])
		{
			ft_reverse_rotate_rra(a);
			ft_reverse_rotate_rra(a);
		}
		else
		{
			ft_swap_sa(a);
			ft_reverse_rotate_rra(a);
		}
	}
}

void	ft_order_5(t_list **a, t_list **b, int *numbers)
{
	t_list	*aux;
	int		position;
	int		i;

	i = 0;
	position = 0;
	aux = *a;
	while(aux != NULL)
	{
		if(aux->content == numbers[i] && i < 2)
		{
			ft_move_a(a, position);
			ft_push_pb(a, b);
			aux = *a;
			position = 0;
			i++;
		}
		else
		{
			position++;
			aux = aux->next;	
		}
	}
	ft_order_5_3(a, numbers);
}

void	ft_order_plus_5(t_list **a, t_list **b, int *numbers)
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
			ft_move_a(a, position);
			ft_push_pb(a, b);
			aux = *a;
			position = 0;
			i++;
		}
		else
		{
			position++;
			aux = aux->next;	
		}
	}
}


