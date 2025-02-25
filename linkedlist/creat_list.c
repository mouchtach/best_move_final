/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:28:39 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/16 21:22:14 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_get_index(int **sorted, int data)
{
	int	i;

	i = 0;
	while (sorted[i])
	{
		if (*sorted[i] == data)
			return (i);
		i++;
	}
	return (-1);
}

t_list	*ft_create_stack(int **input, int count)
{
	t_list	*stack;
	t_list	*tmp;
	int		**sorted;
	int		value;
	int		i;

	stack = NULL;
	i = 0;
	sorted = ft_sort_int_tab(input, count);
	while (i < count)
	{
		value = ft_get_index(sorted, *input[i]);
		tmp = ft_lstnew(*input[i], value);
		if (!tmp)
			return (ft_lstclear(&stack), NULL);
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	ft_free_int(&input);
	ft_free_int(&sorted);
	return (stack);
}
