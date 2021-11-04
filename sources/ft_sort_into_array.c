/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_into_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:07:57 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/04 18:33:24 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ft_pass_to_array(t_list **lst, int size)
{
	int		i;
	int		*numbers;
	t_list	*aux;

	i = 0;
	aux = *lst;
	numbers = malloc(size);
	while (i < size)
	{
		numbers[i] = aux->n;
		i++;
		aux = aux->next;
	}
	return (numbers);
}

int	*ft_sortnumbers(t_list **lst, int size)
{
	int		temp;
	int		i;
	int		j;
	int		*numbers;

	temp = 0;
	i = 0;
	numbers = ft_pass_to_array(lst, size);
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (numbers[j] < numbers[j + 1])
			{
				temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (numbers);
}
