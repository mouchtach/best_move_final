/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:24:03 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/11 10:24:06 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

size_t	ft_get_index(int **sorted, int data)
{
	size_t	i;

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
	int		i;

	stack = NULL;
	i = 0;
	while (i < count)
	{
		tmp = ft_lstnew(*input[i]);
		if (!tmp)
			return (ft_lstclear(&stack), ft_free_int(&input), NULL);
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	ft_free_int(&input);
	return (stack);
}
