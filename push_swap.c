/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:31:47 by ymouchta          #+#    #+#             */
/*   Updated: 2025/03/02 23:21:58 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_if_top(t_list **stack_a, t_list **stack_b, t_list *tmp)
{
	if (tmp->index <= tmp->target->index)
	{
		while (tmp->cost--)
		{
			rr(stack_a, stack_b);
			tmp->target->cost--;
		}
		while (tmp->target->cost--)
			ra(stack_a);
	}
	else
	{
		while (tmp->target->cost--)
		{
			rr(stack_a, stack_b);
			tmp->cost--;
		}
		while (tmp->cost--)
			rb(stack_b);
	}
}

static void	move_if_buttom(t_list **stack_a, t_list **stack_b, t_list *tmp)
{
	if (tmp->cost <= tmp->target->cost)
	{
		while (tmp->cost--)
		{
			rrr(stack_a, stack_b);
			tmp->target->cost--;
		}
		while (tmp->target->cost--)
			rra(stack_a);
	}
	else
	{
		while (tmp->target->cost--)
		{
			rrr(stack_a, stack_b);
			tmp->cost--;
		}
		while (tmp->cost--)
			rrb(stack_b);
	}
}

static void	prepar_to_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = get_min_cost(*stack_b);
	if (tmp->position == 1 && tmp->target->position == 1)
		move_if_top(stack_a, stack_b, tmp);
	else if (tmp->position == 0 && tmp->target->position == 0)
		move_if_buttom(stack_a, stack_b, tmp);
	else if (tmp->position == 1 && tmp->target->position == 0)
	{
		while (tmp->cost--)
			rb(stack_b);
		while (tmp->target->cost--)
			rra(stack_a);
	}
	else
	{
		while (tmp->target->cost--)
			ra(stack_a);
		while (tmp->cost--)
			rrb(stack_b);
	}
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	push(stack_a, stack_b);
	tmp = *stack_a;
	while (tmp)
	{
		set_target(*stack_a, *stack_b);
		set_index(*stack_a, *stack_b);
		set_position(*stack_a, *stack_b);
		set_cost(*stack_a, *stack_b);
		prepar_to_push(stack_a, stack_b);
		pa(stack_a, stack_b);
		tmp = *stack_b;
	}
	set_index(*stack_a, *stack_b);
	set_position(*stack_a, *stack_b);
	set_cost(*stack_a, *stack_b);
	move_a_to_top(stack_a, get_min_data(*stack_a));
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		**int_argv;
	int		count;

	count = 0;
	stack_a = NULL;
	stack_b = NULL;
	int_argv = get_int_arg(argc, argv, &count);
	if (!int_argv)
		return (0);
	stack_a = ft_create_stack(int_argv, count);
	if (!stack_a)
		return (ft_free_int(&int_argv), 1);
	if (count <= 3)
		ft_sort_if_three(&stack_a, &stack_b, count);
	else
		push_swap(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
