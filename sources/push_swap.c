/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:57:29 by msierra-          #+#    #+#             */
/*   Updated: 2021/10/30 20:59:50 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>
#include <unistd.h>
void	ft_add_a(char *str, t_list **a);

//Tengo los numeros ordenados, recorro la lista buscando la ordenación,
//cuando llego al numero que tengo que ordenar, divido la pila *a en dos,
//y veo si renta mas ponerlo arriba rotando hacia arriba o hacia abajo,
//cuando este arriba lo voy pasando a *b, para que se queden ordenados.

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		*numbers;
	int i = 0;

	b = 0;
	a = 0;
	ft_parseint(argc, argv, &a);

	ft_is_sorted(&a);
	numbers = ft_sortnumbers(&a, ft_lstsize(a));
	ft_compare(&a, &b, numbers);
	ft_return_a(&a, &b);
	
	while(a)
	{
		printf("a: %d\n", a->content);
		a = a->next;
	}
	while(b)
	{
		printf("b: %d\n", b->content);
		b = b->next;
	}
	
}

void	ft_add_a(char *str, t_list **a)
{
	int numbers;

	if(ft_strlen(str) <= 0)
		ft_errormsg();
	numbers = ft_atoi(str);
	ft_repeatnumbers(a, numbers);
	ft_lstadd_front(a, ft_lstnew(numbers));
}