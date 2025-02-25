/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:27:08 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/11 10:27:10 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_str(char **str)
{
	if (!str || !(*str))
		return ;
	free(*str);
	*str = NULL;
}

void	ft_free_tab_str(char ***str)
{
	int	i;

	i = 0;
	if (!str || !(*str)) 
		return ;
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
	*str = NULL;
}

void	ft_free_int(int ***tab)
{
	int	i;

	i = 0;
	if (*tab)
	{
		while ((*tab)[i])
		{
			free((*tab)[i]); 
			(*tab)[i] = NULL;
			i++;
		}
		free(*tab); 
		*tab = NULL;
	}
}

void	ft_free_stack(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL; 
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
