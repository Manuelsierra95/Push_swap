/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_into_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:07:57 by msierra-          #+#    #+#             */
/*   Updated: 2021/10/30 20:58:18 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

//Ordenar en bloques tomando como referencia una lista ya ordenada


// int	ft_minnumber(t_list **lst)
// {
// 	t_list	*aux;
// 	int		min;

// 	aux = *lst;
// 	// printf("Valor de i despues: %d\t", i);
// 	while(aux->next)
// 	{
// 		if(aux->content < aux->next->content)
// 			min = aux->content;
// 		aux = aux->next;
// 	}
// 	if(aux->content < min)
// 		min = aux->content;
// 	printf("Min: %d\n", min);
// 	return (min);
// }

// void	ft_sortnumbers(t_list **lst)
// {
// 	t_list	*aux;
// 	t_list	*head;
// 	int		min;
// 	int		i;

// 	i = 0;
// 	head = *lst;
// 	while(aux)
// 	{
// 		//printf("Valor de i antes: %d\t", i);
// 		min = ft_minnumber(&aux, i);
// 		if(aux->content == min)
// 		{
// 			aux->content = i;
// 			aux = head;
// 			i++;
// 		}
// 		else
// 			aux = aux->next;
// 	}
// }

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
		numbers[i] = aux->content;
		i++;
		aux = aux->next;
	}
	return (numbers);
}

int	*ft_sortnumbers(t_list **lst, int size)//Ordenacion burbuja
{
	int		temp;
	int		i;
	int		j;
	int		*numbers;

	temp = 0;
	i = 0;
	numbers = ft_pass_to_array(lst, size);
	while(i < size)
	{
		j = 0;
		while(j < size - 1)
		{
			if(numbers[j] > numbers[j + 1])
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

// void	ft_reducenumbers(t_list *lst)
// {
// 	t_list	*aux;
// 	int		i;
	
// 	i = 0;
// 	aux = *lst;
// 	ft_sortnumbers(&aux);
// 	while(aux != NULL)
// 	{
// 		aux->content = i;
// 		i++;
// 		aux = aux->next;
// 	}	
// }