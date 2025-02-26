/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:31:58 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/16 21:26:43 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_min_target(t_list *stack_a, t_list *node)
{
	t_list	*tmp;
	t_list	*small;

	tmp = stack_a;
	small = stack_a;
	while (tmp)
	{
		if (small->data > tmp->data)
			small = tmp;
		tmp = tmp->next;
	}
	node->target = small;
}

void	set_target(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp_b;
	t_list	*tmp_a;

	tmp_b = stack_b;
	tmp_a = stack_a;
	while (tmp_b)
	{
		tmp_b->target = tmp_a;
		while (tmp_a)
		{
			if (tmp_a->data > tmp_b->data)
			{
				if (tmp_b->data > tmp_b->target->data
					|| tmp_a->data < tmp_b->target->data)
					tmp_b->target = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (tmp_b->data > tmp_b->target->data)
			set_min_target(stack_a, tmp_b);
		tmp_a = stack_a;
		tmp_b = tmp_b->next;
	}
}

void	set_index(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;
	int		index;

	index = 0;
	tmp = stack_a;
	while (tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
	tmp = stack_b;
	index = 0;
	while (tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
}

void	set_cost(t_list *stack_a, t_list *stack_b)
{
	int		len_a;
	int		len_b;
	t_list	*tmp;

	len_b = ft_lstsize(stack_b);
	len_a = ft_lstsize(stack_a);
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->position == 1)
			tmp->cost = tmp->index;
		else
			tmp->cost = len_a - tmp->index;
		tmp = tmp->next;
	}
	tmp = stack_b;
	while (tmp)
	{
		if (tmp->position == 1)
			tmp->cost = tmp->index;
		else
			tmp->cost = len_b - tmp->index;
		tmp = tmp->next;
	}
}

void	set_position(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;
	int		len_a;
	int		len_b;

	tmp = stack_a;
	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (tmp)
	{
		if (tmp->index <= len_a / 2)
			tmp->position = 1;
		else
			tmp->position = 0;
		tmp = tmp->next;
	}
	tmp = stack_b;
	while (tmp)
	{
		if (tmp->index <= len_b / 2)
			tmp->position = 1;
		else
			tmp->position = 0;
		tmp = tmp->next;
	}
}
