/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:49:40 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/01 18:32:01 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void ft_rotate_ra(t_list **a)
{
	t_list	*aux;
	
	if(ft_lstsize(*a) > 1)
	{
		aux = *a;//Aux apunta a la 1 pos
		ft_lstadd_back(a, aux);//Ponemos aux al final
		*a = (*a)->next;//Movemos *a una pos
		aux->next = NULL;//Aux que es el ultimo nodo, lo apuntamos a NULL
		write(1, "ra\n", 3);
	}
}

void ft_rotate_rb(t_list **b)
{
	t_list	*aux;
	
	if(ft_lstsize(*b) > 1)
	{
		aux = *b;
		ft_lstadd_back(b, aux);
		*b = (*b)->next;
		aux->next = NULL;
		write(1, "rb\n", 3);
	}
}

void ft_rotate_rr(t_list **a, t_list **b)
{
	t_list	*aux;
	
	if(ft_lstsize(*a) > 1)
	{
		aux = *a;
		ft_lstadd_back(a, aux);
		*a = (*a)->next;
		aux = *b;
		ft_lstadd_back(b, aux);
		*b = (*b)->next;
		aux->next = NULL;
		write(1, "rr\n", 3);
	}
}

void ft_reverse_rotate_rra(t_list **a)
{
	t_list	*last;
	t_list	*aux;
	
	if(ft_lstsize(*a) > 1)
	{
		aux = *a;
		last = ft_lstlast(*a);
		while(aux->next->next)//Movemos la lista hasta la penultima pos
			aux = aux->next;
		aux->next = NULL;//Apuntamos el ultimo elemento a NULL
		ft_lstadd_front(a, last);//Añadimos al principio last
		write(1, "rra\n", 4);
	}
}

void ft_reverse_rotate_rrb(t_list **b)
{
	t_list	*last;
	t_list	*aux;
	
	if(ft_lstsize(*b) > 1)
	{
		aux = *b;
		last = ft_lstlast(*b);
		while(aux->next->next)
			aux = aux->next;
		aux->next = NULL;
		ft_lstadd_front(b, last);
		write(1, "rra\n", 4);
	}
}
