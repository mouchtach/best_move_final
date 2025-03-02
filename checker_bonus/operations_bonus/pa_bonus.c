/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:26:09 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/11 10:26:12 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if (!lst_b || !*lst_b)
		return ;
	tmp = (*lst_b)->next;
	(*lst_b)->next = *lst_a;
	*lst_a = *lst_b;
	*lst_b = tmp;
}
