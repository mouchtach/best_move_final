/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:31:26 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/16 21:13:29 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_index_data(t_list *stack, int value)
{
	t_list	*tmp;
	int		index;

	tmp = stack;
	index = 0;
	while (tmp)
	{
		if (tmp->data == value)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;

	tmp = *stack_a;
	int len = ft_lstsize(*stack_a);
	int rang = len;
	tmp = *stack_a;
	while (len--)
	{
		if((*stack_a)->value <= rang / 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	len = ft_lstsize(*stack_a);
	while (len-- > 3)
		pb(stack_a, stack_b);
	
	ft_sort_three(stack_a);
	

	// t_list	*tmp;
	// int		range;

	// range = get_range(*stack_a);
	// tmp = *stack_a;
	// while (tmp && ft_lstsize(*stack_a) > 3)
	// {
	// 	if (tmp->data <= range)
	// 	{
	// 		ft_move_node_a_to_top(stack_a, tmp->data);
	// 		pb(stack_a, stack_b);
	// 		tmp = *stack_a;
	// 	}
	// 	else
	// 		tmp = tmp->next;
	// }
	// tmp = *stack_a;
}

void	ft_move_node_b_to_top(t_list **stack, int value)
{
	int	target;

	target = find_index_data(*stack, value);
	if (target == 0)
		return ;
	if (target <= ft_lstsize(*stack) / 2)
	{
		while (target > 0)
		{
			rb(stack);
			target--;
		}
	}
	else
	{
		while (target < ft_lstsize(*stack))
		{
			rrb(stack);
			target++;
		}
	}
}

void	ft_move_node_a_to_top(t_list **stack, int value)
{
	int	target;

	target = find_index_data(*stack, value);
	if (target == 0)
		return ;
	if (target <= ft_lstsize(*stack) / 2)
	{
		while (target > 0)
		{
			ra(stack);
			target--;
		}
	}
	else
	{
		while (target < ft_lstsize(*stack))
		{
			rra(stack);
			target++;
		}
	}
}

int	get_min_stack(t_list *stack)
{
	t_list	*tmp;
	int		min;

	tmp = stack;
	min = stack->data;
	while (tmp)
	{
		if (min > tmp->data)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}
