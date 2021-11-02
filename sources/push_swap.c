/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:57:29 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/02 18:34:16 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>
#include <unistd.h>

void	ft_order(t_list **a, t_list **b, int *numbers)
{
	int	size;

	size = ft_lstsize(*a);
	if(size <= 3)
		ft_order_3(a, numbers);
	else if(size > 3 && size <= 5)
		ft_order_5(a, b, numbers);
	else
		ft_execute(a, b, numbers);
}

void	ft_add_a(char *str, t_list **a)
{
	int numbers;

	numbers = ft_atoi(str);
	ft_repeatnumbers(a, numbers);
	ft_lstadd_back(a, ft_lstnew(numbers));
}

void	ft_return_a(t_list **a, t_list **b)
{
	while(*b)
		ft_push_pa(a, b);
}

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		*numbers;

	b = 0;
	a = 0;
	ft_voidstr(argc, argv);
	ft_parseint(argc, argv, &a);
	ft_is_sorted(&a);
	numbers = ft_sortnumbers(&a, ft_lstsize(a));
	ft_order(&a, &b, numbers);
	ft_return_a(&a, &b);
}
