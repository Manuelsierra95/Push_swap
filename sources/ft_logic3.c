/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:28:26 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/04 18:21:13 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_ifdoublerotate(t_list **a)
{
	int		i;
	t_list	*aux;

	aux = *a;
	i = 0;
	if (aux->n < aux->next->n)
		return (1);
	else
		return (0);
}

int	ft_ifdoublereverse(t_list **a)
{
	int		i;
	t_list	*aux;
	t_list	*aux2;

	aux = *a;
	aux2 = ft_lstlast(*a);
	i = 0;
	if (aux->n < aux2->n)
		return (1);
	else
		return (0);
}
