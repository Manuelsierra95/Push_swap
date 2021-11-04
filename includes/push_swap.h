/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:01:39 by msierra-          #+#    #+#             */
/*   Updated: 2021/11/04 18:15:00 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/*
	Required
*/
# include <stdlib.h>
# include <unistd.h>
typedef struct s_list
{
	int				n;
	int				size;
	struct s_list	*next;
}	t_list;
typedef struct s_pivot
{
	int				pivot1;
	int				pivot2;
	int				position;
}	t_pivot;
/*
	Errors
*/
void	ft_is_sorted(t_list **a);
void	ft_repeatnumbers(t_list **a, int numbers);
void	ft_errormsg(void);
void	ft_char_error(char *argv);
void	ft_voidstr(int argc, char **argv, int flag);
int		ft_voidstr2(char *argv);
/*
	List
*/
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/*
	Parse & add
*/
void	ft_parseint(int argc, char **argv, t_list **a);
void	ft_add_a(char *str, t_list **a);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
/*
	Movements
*/
void	ft_swap_sa(t_list **a);
void	ft_swap_sb(t_list **b);
void	ft_swap_ss(t_list **a, t_list **b);
void	ft_push_pa(t_list **a, t_list **b);
void	ft_push_pb(t_list **a, t_list **b);
void	ft_rotate_ra(t_list **a);
void	ft_rotate_rb(t_list **b);
void	ft_rotate_rr(t_list **a, t_list **b);
void	ft_reverse_rotate_rra(t_list **a);
void	ft_reverse_rotate_rrb(t_list **b);
void	ft_reverse_rotate_rrr(t_list **a, t_list **b);
/*
	Logic
*/
int		*ft_sortnumbers(t_list **lst, int size);
int		*ft_pass_to_array(t_list **lst, int size);
void	ft_return_a(t_list **a, t_list **b);
void	ft_move_a(t_list **a, t_pivot pivot);
void	ft_order_a(t_list **a, t_list **b, int *numbers, t_pivot pivot);
void	ft_order_b(t_list **a, t_list **b, int *numbers, t_pivot pivot);
void	ft_order_5(t_list **a, t_list **b, int *numbers);
void	ft_order_3(t_list **a);
void	ft_quick_sort(t_list **a, t_list **b, int *numbers, t_pivot pivot);
int		ft_maxsize(int pivot, int *numbers);
int		ft_ifdoublerotate(t_list **a);
int		ft_ifdoublereverse(t_list **a);
void	ft_execute(t_list **a, t_list **b, int *numbers, int divide);
void	ft_order_4(t_list **a, t_list **b, int *numbers);
#endif
