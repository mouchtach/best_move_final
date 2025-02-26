/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:31:35 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/16 21:26:13 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_sort(int **tab, int count)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	if (!tab)
		return ;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (*tab[i] > *tab[j])
			{
				tmp = *tab[i];
				*tab[i] = *tab[j];
				*tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	tab[i] = NULL;
}

int	ft_get_cost(t_list *stack_a, t_list *stack_b, t_list *tar)
{
	int	cost;
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a) - tar->target->index;
	len_b = ft_lstsize(stack_b) - tar->index;
	if (tar->position == 1 && tar->target->position == 1)
	{
		if (tar->index >= tar->target->index)
			cost = tar->index;
		else
			cost = tar->target->index;
	}
	else if (tar->position == 0 && tar->target->position == 0)
	{
		if (len_a >= len_b)
			cost = len_a;
		else
			cost = len_b;
	}
	else if (tar->position == 0 && tar->target->position == 1)
		cost = tar->target->index + (ft_lstsize(stack_b) - tar->index);
	else
		cost = tar->index + (ft_lstsize(stack_a) - tar->target->index);
	return (cost);
}

int	**ft_sort_int_tab(int **tab, int count)
{
	int	**sort_int;
	int	i;

	i = 0;
	sort_int = NULL;
	sort_int = (int **)malloc(sizeof(int *) * (count + 1));
	if (!sort_int)
		return (ft_free_int(&sort_int), ft_free_int(&tab), NULL);
	while (i < count)
	{
		sort_int[i] = malloc(sizeof(int));
		if (!sort_int[i])
			return (ft_free_int(&sort_int), ft_free_int(&tab), NULL);
		*sort_int[i] = *tab[i];
		i++;
	}
	ft_sort(sort_int, count);
	return (sort_int);
}
