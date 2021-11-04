/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:57:29 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/04 18:29:18 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_order(t_list **a, t_list **b, int *numbers)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
	{
		if ((*a)->n == numbers[0])
			ft_swap_sa(a);
	}	
	else if (size == 3)
		ft_order_3(a);
	else if (size == 4)
		ft_order_4(a, b, numbers);
	else if (size == 5)
		ft_order_5(a, b, numbers);
	else if (size > 5 && size < 100)
		ft_execute(a, b, numbers, 1);
	else if (size >= 100 && size < 500)
		ft_execute(a, b, numbers, 4);
	else if (size >= 500 && size < 1001)
		ft_execute(a, b, numbers, 8);
}

void	ft_add_a(char *str, t_list **a)
{
	int	numbers;

	numbers = ft_atoi(str);
	ft_repeatnumbers(a, numbers);
	ft_lstadd_back(a, ft_lstnew(numbers));
}

void	ft_return_a(t_list **a, t_list **b)
{
	while (*b)
		ft_push_pa(a, b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		*numbers;

	if (argc == 1)
		exit(0);
	b = 0;
	a = 0;
	ft_voidstr(argc, argv, 1);
	ft_parseint(argc, argv, &a);
	ft_is_sorted(&a);
	numbers = ft_sortnumbers(&a, ft_lstsize(a));
	ft_order(&a, &b, numbers);
	ft_return_a(&a, &b);
}
