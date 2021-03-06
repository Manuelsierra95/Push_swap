/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:09:09 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/04 18:33:15 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse_rotate_rrr(t_list **a, t_list **b)
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
		last = ft_lstlast(*b);
		aux = *b;
		while (aux->next->next)
			aux = aux->next;
		aux->next = NULL;
		ft_lstadd_front(b, last);
		write(1, "rrr\n", 4);
	}
}
