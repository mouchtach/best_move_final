/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:31:15 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/16 21:02:55 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_tow(t_list **lst)
{
	if (!lst || !*lst || !(*lst)->next)
		return ;
	if ((*lst)->data > (*lst)->next->data)
		sa(lst);
}

void	ft_sort_three(t_list **lst)
{
	int	a;
	int	b;
	int	c;

	a = (*lst)->data;
	b = (*lst)->next->data;
	c = (*lst)->next->next->data;
	if (a > b && a > c && b > c)
	{
		ra(lst);
		sa(lst);
	}
	else if (a > b && a > c && c > b)
		ra(lst);
	else if (a > b && a < c)
		sa(lst);
	else if (c < b && c < a && b > a)
		rra(lst);
	else if (a < b && a < c && b > c)
	{
		rra(lst);
		sa(lst);
	}
	else
		return ;
}

// int	get_range(t_list *stack)
// {
// 	t_list	*tmp;
// 	int		total;

// 	tmp = stack;
// 	total = 0;
// 	while (tmp)
// 	{
// 		total += tmp->data;
// 		tmp = tmp->next;
// 	}
// 	return (total / ft_lstsize(stack));
// }

t_list	*get_min_cost(t_list *stack)
{
	t_list	*small;

	small = stack;
	while (stack)
	{
		if ((small->cost + small->target->cost) > (stack->cost + stack->target->cost))
			small = stack;
		stack = stack->next;
	}
	return (small);
}

void	ft_sort_if_three(t_list **lst_a, t_list **lst_b, int count)
{
	if (count == 2)
		ft_sort_tow(lst_a);
	else 
		ft_sort_three(lst_a);
}
